#include "machine.h"

static void setState(machine_ctx_t *pstCtx, machine_state_e state)
{
    if (state == pstCtx->state)
    {
        return;
    }

    pstCtx->lastState = state;

    switch (state)
    {
    case MACHINE_STATE_RUNNING:
        break;
    case MACHINE_STATE_STOPPING:
        break;
    case MACHINE_STATE_DOFFING:
        break;
    }
}

static void updateMachineAlarmLevel(machine_ctx_t *pstCtx)
{
}

static void updateMachineEndBreaks(machine_ctx_t *pstCtx, uint16_t usSpindleID, bool bIsBroken)
{
}

static void updateMainAxleSpeed(machine_ctx_t *pstCtx, uint16_t usSpeed)
{
}

void machineTaskEntry(void *arg)
{
    machine_ctx_t ctx;

    while (1)
    {
    }
}

void machineInit(void)
{
}