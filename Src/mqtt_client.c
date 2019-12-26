#include "los_base.h"
#include "los_task.ph"
#include "los_typedef.h"
#include "los_sys.h"
#include "log/atiny_log.h"
#include "MQTTClient.h"
#include "cJSON.h"

#define MQTT_VERSION_3_1 (3)
#define MQTT_VERSION_3_1_1 (4)

#define VARIABLE_SIZE (4 + 1)
#define CMD_TOPIC_FMT "/huawei/v1/devices/%s/command/%s"
#define DATA_TOPIC_FMT "/huawei/v1/devices/%s/data/%s"
#define SECRET_NOTIFY_TOPIC_FMT "/huawei/v1/products/%s/sn/%s/secretNotify"
#define SECRET_ACK_TOPIC_FMT "/huawei/v1/products/%s/sn/%s/secretACK"

#define MQTT_TIME_BUF_LEN 11

#define IS_VALID_NAME_LEN(name) (strnlen((name), STRING_MAX_LEN + 1) <= STRING_MAX_LEN)

typedef enum
{
    MQTT_CONNECT_WITH_PRODUCT_ID,
    MQTT_CONNECT_WITH_DEVICE_ID
} mqtt_dynamic_connect_state_e;

typedef struct
{
    mqtt_static_connection_info_s save_info;
    char *got_password;
    mqtt_dynamic_connect_state_e state;
    uint8_t connection_update_flag;
    uint8_t has_device_id; //
    uint8_t reserve[2];
} mqtt_dynamic_info_s;

struct mqtt_client_tag_s
{
    mqtt_device_info_s device_info;
    MQTTClient client;
    mqtt_param_s params;
    mqtt_dynamic_info_s dynamic_info;
    char *sub_topic;
    uint8_t init_flag;
    uint8_t reserve[3];
};

static uint8_t g_mqtt_sendbuf[MQTT_SENDBUF_SIZE];
static uint8_t g_mqtt_readbuf[MQTT_READBUF_SIZE + 1];

static mqtt_client_s g_mqtt_client;

static int mqtt_cmd_ioctl(mqtt_cmd_e cmd, void *arg, int32_t len)
{
    mqtt_client_s *handle = &g_mqtt_client;

    if (handle->params.cmd_ioctl != NULL)
    {
        return handle->params.cmd_ioctl(cmd, arg, len);
    }
    ATINY_LOG(LOG_FATAL, "cmd_ioctl null");
    return ATINY_ERR;
}

static void mqtt_disconnect(MQTTClient *client, Network *n)
{
    if (MQTTIsConnected(client))
    {
        (void)MQTTDisconnect(client);
    }
    NetworkDisconnect(n);

    ATINY_LOG(LOG_ERR, "mqtt_disconnect");
}

static inline void mqtt_inc_fail_cnt(int32_t *conn_failed_cnt)
{
    if (*conn_failed_cnt < MQTT_CONN_FAILED_MAX_TIMES)
    {
        (*conn_failed_cnt)++;
    }
}

static void mqtt_proc_connect_err(MQTTClient *client, Network *n, int32_t *conn_failed_cnt)
{
    mqtt_inc_fail_cnt(conn_failed_cnt);
    mqtt_disconnect(client, n);
}

int atiny_mqtt_init(const mqtt_param_s *params, mqtt_client_s **phandle)
{
    cJSON_InitHooks(NULL);

    if (params == NULL || phandle == NULL || mqtt_check_param(params) != ATINY_OK)
    {
        ATINY_LOG(LOG_FATAL, "Invalid args");
        return ATINY_ARG_INVALID;
    }

    if (g_mqtt_client.init_flag)
    {
        ATINY_LOG(LOG_FATAL, "mqtt reinit");
        return ATINY_ERR;
    }

    memset(&g_mqtt_client, 0, sizeof(g_mqtt_client));

    if (ATINY_OK != mqtt_dup_param(&(g_mqtt_client.params), params))
    {
        return ATINY_MALLOC_FAILED;
    }

    *phandle = &g_mqtt_client;

    g_mqtt_client.init_flag = true;

    return ATINY_OK;
}

int atiny_mqtt_bind(const mqtt_device_info_s *device_info, mqtt_client_s *handle)
{
    Network n;
    MQTTClient *client = NULL;
    mqtt_param_s *params;
    int rc;
    int32_t conn_failed_cnt = 0;
    MQTTPacket_connectData data = MQTTPacket_connectData_initializer;
    Timer timer;
    int result = ATINY_ERR;

    if (NULL == handle)
    {
        ATINY_LOG(LOG_FATAL, "handle null");
        return ATINY_ARG_INVALID;
    }

    if ((device_info == NULL) || (mqtt_check_device_info(device_info) != ATINY_OK))
    {
        ATINY_LOG(LOG_FATAL, "parameter invalid");
        result = ATINY_ARG_INVALID;
        goto atiny_bind_quit;
    }

    client = &(handle->client);
    params = &(handle->params);

    rc = mqtt_dup_device_info(&(handle->device_info), device_info);
    if (rc != ATINY_OK)
    {
        goto atiny_bind_quit;
    }

    NetworkInit(&n, mqtt_get_security_info);

    memset(client, 0x0, sizeof(MQTTClient));
    rc = MQTTClientInit(client, &n, MQTT_COMMAND_TIMEOUT_MS, g_mqtt_sendbuf, MQTT_SENDBUF_SIZE, g_mqtt_readbuf, MQTT_READBUF_SIZE);
    if (rc != MQTT_SUCCESS)
    {
        ATINY_LOG(LOG_FATAL, "MQTTClientInit fail,rc %d", rc);
        goto atiny_bind_quit;
    }

    data.willFlag = 0;
    data.MQTTVersion = MQTT_VERSION_3_1_1;
    data.keepAliveInterval = MQTT_KEEPALIVE_INTERVAL_S;
    data.cleansession = true;

    while (true)
    {
        if (conn_failed_cnt > 0)
        {
            ATINY_LOG(LOG_INFO, "reconnect delay : %d", conn_failed_cnt);
            (void)LOS_TaskDelay(MQTT_CONN_FAILED_BASE_DELAY << conn_failed_cnt);
        }

        rc = NetworkConnect(&n, params->server_ip, atoi(params->server_port));
        if (rc != 0)
        {
            ATINY_LOG(LOG_ERR, "NetworkConnect fail: %d", rc);
            mqtt_inc_fail_cnt(&conn_failed_cnt);
            continue;
        }

        if (mqtt_get_connection_info(handle, &data) != ATINY_OK)
        {
            mqtt_destroy_data_connection_info(&data);
            mqtt_proc_connect_err(client, &n, &conn_failed_cnt);
            continue;
        }

        rc = MQTTConnect(client, &data);
        mqtt_destroy_data_connection_info(&data);
        ATINY_LOG(LOG_DEBUG, "CONNACK : %d", rc);
        if (MQTT_SUCCESS != rc)
        {
            // receive connection nack value
            if (rc != MQTT_SUCCESS)
            {
                mqtt_proc_connect_nack(handle);
            }
            ATINY_LOG(LOG_ERR, "MQTTConnect failed %d", rc);
            mqtt_proc_connect_err(client, &n, &conn_failed_cnt);
            continue;
        }

        if (ATINY_OK != mqtt_subscribe_topic(handle))
        {
            ATINY_LOG(LOG_ERR, "mqtt_subscribe_topic failed");
            mqtt_proc_connect_err(client, &n, &conn_failed_cnt);
            continue;
        }

        conn_failed_cnt = 0;
        if (!mqtt_is_connectting_with_deviceid(handle))
        {
            TimerInit(&timer);
            TimerCountdownMS(&timer, MQTT_WRITE_FOR_SECRET_TIMEOUT);
        }
        while (rc >= 0 && MQTTIsConnected(client))
        {
            rc = MQTTYield(client, MQTT_EVENTS_HANDLE_PERIOD_MS);

            // receive secret info
            if (handle->dynamic_info.connection_update_flag)
            {
                ATINY_LOG(LOG_INFO, "recv secret info");
                ATINY_LOG(LOG_DEBUG, "secret info deviceid %s", handle->dynamic_info.save_info.deviceid);
                handle->dynamic_info.connection_update_flag = false;
                handle->dynamic_info.state = MQTT_CONNECT_WITH_DEVICE_ID;
                break;
            }

            // wait secret info timeout.
            if (!mqtt_is_connectting_with_deviceid(handle) && (TimerIsExpired(&timer)))
            {
                if (handle->dynamic_info.has_device_id)
                {
                    handle->dynamic_info.state = MQTT_CONNECT_WITH_DEVICE_ID;
                }
                break;
            }
        }

        mqtt_disconnect(client, &n);
    }

    result = ATINY_OK;
atiny_bind_quit:
    mqtt_free_dynamic_info(handle);
    mqtt_free_params(&(handle->params));
    (void)atiny_task_mutex_lock(&client->mutex);
    mqtt_free_device_info(&(handle->device_info));
    (void)atiny_task_mutex_unlock(&client->mutex);
    MQTTClientDeInit(client);
    handle->init_flag = false;
    return result;
}

int atiny_mqtt_data_send(mqtt_client_s *phandle, const char *msg, uint32_t msg_len, mqtt_qos_e qos)
{
    MQTTMessage message;
    int rc;
    char *topic;
    size_t payloadlen;

    if ((phandle == NULL) || (qos >= MQTT_QOS_MAX))
    {
        ATINY_LOG(LOG_FATAL, "Parameter invalid");
        return ATINY_ARG_INVALID;
    }
    if (phandle->device_info.codec_mode == MQTT_CODEC_MODE_JSON)
    {
        if (msg == NULL || msg_len <= 0)
        {
            ATINY_LOG(LOG_FATAL, "msg invalid");
            return ATINY_ARG_INVALID;
        }
        payloadlen = strnlen(msg, msg_len);
    }
    else
    {
        if (msg == NULL && msg_len > 0)
        {
            ATINY_LOG(LOG_FATAL, "msg invalid");
            return ATINY_ARG_INVALID;
        }
        payloadlen = msg_len;
    }

    if (!atiny_mqtt_isconnected(phandle))
    {
        ATINY_LOG(LOG_FATAL, "not connected");
        return ATINY_ERR;
    }

    topic = mqtt_get_device_topic(phandle, DATA_TOPIC_FMT, sizeof(DATA_TOPIC_FMT) - VARIABLE_SIZE);
    if (topic == NULL)
    {
        return ATINY_MALLOC_FAILED;
    }
    memset(&message, 0, sizeof(message));
    message.qos = (enum QoS)qos;
    message.payload = (void *)msg;
    message.payloadlen = payloadlen;
    rc = MQTTPublish(&phandle->client, topic, &message);
    atiny_free(topic);
    if (rc != MQTT_SUCCESS)
    {
        ATINY_LOG(LOG_FATAL, "MQTTPublish fail,rc %d", rc);
        return ATINY_ERR;
    }
    return ATINY_OK;
}

int atiny_mqtt_isconnected(mqtt_client_s *phandle)
{
    if (NULL == phandle)
    {
        ATINY_LOG(LOG_ERR, "invalid args");
        return false;
    }
    return mqtt_is_connectting_with_deviceid(phandle) && MQTTIsConnected(&(phandle->client));
}