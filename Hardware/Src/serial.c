#include "serial.h"
#include "los_devfs.h"
#include "stm32f1xx_hal.h"
#include "sys/errno.h"
#include "usart.h"

static int serial_open(void* dev, int flags)
{
    UART_HandleTypeDef* huart = (UART_HandleTypeDef*)dev;

    return HAL_UART_Init(huart);
}

static int serial_close(void* dev)
{
    return 0;
}

static ssize_t serial_read(void* dev, char* ch, size_t size)
{
    UART_HandleTypeDef* huart = (UART_HandleTypeDef*)dev;

    HAL_UART_Receive(huart, (uint8_t*)ch, size, HAL_MAX_DELAY);

    return huart->RxXferSize - huart->RxXferCount;
}

static ssize_t serial_write(void* dev, const char* ch, size_t size)
{
    UART_HandleTypeDef* huart = (UART_HandleTypeDef*)dev;

    HAL_UART_Transmit(huart, (uint8_t*)ch, size, HAL_MAX_DELAY);

    return huart->TxXferSize - huart->TxXferCount;
}

static int serial_ioctl(void* dev, int cmd, unsigned long arg)
{
    UART_HandleTypeDef* huart = (UART_HandleTypeDef*)dev;

    switch (cmd) {
    case SERIAL_IOC_BAUDRATE:
        switch (arg) {
        case B2400:
            huart->Init.BaudRate = 2400;
            break;
        case B4800:
            huart->Init.BaudRate = 4800;
            break;
        case B9600:
            huart->Init.BaudRate = 9600;
            break;
        case B19200:
            huart->Init.BaudRate = 19200;
            break;
        case B38400:
            huart->Init.BaudRate = 38400;
            break;
        case B115200:
            huart->Init.BaudRate = 115200;
            break;
        default:
            errno = ENOTSUP;
            return -1;
        }
        break;
    case SERIAL_IOC_DATA_LENGTH:
        switch (arg) {
        case DATA_BITS_8:
            huart->Init.WordLength = UART_WORDLENGTH_8B;
            break;
        case DATA_BITS_9:
            huart->Init.WordLength = UART_WORDLENGTH_9B;
            break;
        default:
            errno = ENOTSUP;
            return -1;
        }
    case SERIAL_IOC_STOP_BITS:
        switch (arg) {
        case STOP_BITS_1:
            huart->Init.StopBits = UART_STOPBITS_1;
            break;
        case STOP_BITS_2:
            huart->Init.StopBits = UART_STOPBITS_2;
            break;
        default:
            errno = ENOTSUP;
            return -1;
        }
        break;
    case SERIAL_IOC_PARITY:
        switch (arg) {
        case PARITY_NONE:
            huart->Init.Parity = UART_PARITY_NONE;
            break;
        case PARITY_EVEN:
            huart->Init.Parity = UART_PARITY_EVEN;
            break;
        case PARITY_ODD:
            huart->Init.Parity = UART_PARITY_ODD;
            break;
        default:
            errno = ENOTSUP;
            return -1;
        }
        break;
    default:
        errno = ENOTSUP;
        return -1;
    }

    HAL_UART_Init(huart);

    return 0;
}

static struct devfs_ops serial_ops = {
    .kiops = {
        .open = serial_open,
        .close = serial_close,
        .read = serial_read,
        .write = serial_write,
        .ioctl = serial_ioctl,
    },
};

int serial_init(void)
{
    los_devfs_create("uart4", KIFS_ATTR_R | KIFS_ATTR_W, &serial_ops, &huart4);

    return 0;
}
