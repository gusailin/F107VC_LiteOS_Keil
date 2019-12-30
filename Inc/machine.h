typedef enum
{
    MACHINE_STATE_STOPPING,
    MACHINE_STATE_RUNNING,
    MACHINE_STATE_DOFFING,
} machine_state_e;

typedef enum
{
    MACHINE_DETECTION_OFF,
    MACHINE_DETECTION_ON,
} machine_detection_state_e;

typedef struct
{
    uint16_t usRollDiameter;
    uint16_t usWharveDiameter;
    uint16_t usDetectionOpenDelaySec;
    uint16_t usDetectionRatio;
    uint16_t usWeakTwistRatio;
};

typedef struct
{
    uint16_t usMainAxleSpeed;                 /* 主轴转速 */
    uint16_t usSpindleSpeed;                  /* 锭速 */
    machine_state_e currentState, lastState;  /* 机器状态 */
    machine_detection_state_e detectionState; /* 检测状态 */
    uint16_t usCurrentDoffingTimeSec;         /* 落纱时间 */
} machine_ctx_t;