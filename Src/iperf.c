#include <stdint.h>
#include <stdio.h>
#include "lwip/sockets.h"
#include "lwip/sys.h"
#include "lwip/api.h"
#include "iperf.h"

#include "los_memory.h"
#include "los_task.h"

#define IPERF_PORT 5001
#define IPERF_BUFSZ (4 * 1024)

UINT32 g_uwIperfTaskID;

void iperf_server(void *thread_param)
{
    uint8_t *recv_data;
    socklen_t sin_size;
    int sock = -1, connected, bytes_received;
    struct sockaddr_in server_addr, client_addr;
    fd_set readset;
    struct timeval timeout;

    recv_data = (uint8_t *)LOS_MemAlloc(m_aucSysMem0, IPERF_BUFSZ);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        goto __exit;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(IPERF_PORT);
    memset(&server_addr.sin_zero, 0, sizeof(server_addr.sin_zero));

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1)
    {
        goto __exit;
    }

    if (listen(sock, 5) == -1)
    {
        goto __exit;
    }

    timeout.tv_sec = 3;
    timeout.tv_usec = 0;

    while (1)
    {
        FD_ZERO(&readset);
        FD_SET(sock, &readset);

        if (select(sock + 1, &readset, NULL, NULL, &timeout) == 0)
        {
            continue;
        }

        sin_size = sizeof(struct sockaddr_in);
        connected = accept(sock, (struct sockaddr *)&client_addr, &sin_size);

        {
            int flag = 1;
            setsockopt(connected, IPPROTO_TCP, TCP_NODELAY, (void *)&flag, sizeof(int));
            while (1)
            {
                bytes_received = recv(connected, recv_data, IPERF_PORT, 0);
                if (bytes_received <= 0)
                    break;
            }
        }
    }

__exit:
    if (sock >= 0)
        closesocket(sock);

    if (recv_data)
        LOS_MemFree(m_aucSysMem0, recv_data);
}

void iperf_server_init(void)
{
    UINT32 uwRet = LOS_OK;
    TSK_INIT_PARAM_S task;

    task.usTaskPrio = 3;
    task.pcName = "iperf_server";
    task.pfnTaskEntry = (TSK_ENTRY_FUNC)iperf_server;
    task.uwStackSize = 1024;

    uwRet = LOS_TaskCreate(&g_uwIperfTaskID, &task);
}
