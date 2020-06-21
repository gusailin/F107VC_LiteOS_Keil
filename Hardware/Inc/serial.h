#ifndef INC_SERIAL_H_
#define INC_SERIAL_H_

#define SERIAL_IOC_BAUDRATE 0x0
#define SERIAL_IOC_DATA_LENGTH 0x1
#define SERIAL_IOC_STOP_BITS 0x2
#define SERIAL_IOC_PARITY 0x3

#define B2400 0
#define B4800 1
#define B9600 2
#define B19200 3
#define B38400 4
#define B115200 5

#define DATA_BITS_8 8
#define DATA_BITS_9 9

#define STOP_BITS_1 1
#define STOP_BITS_2 2

#define PARITY_NONE 0
#define PARITY_ODD 1
#define PARITY_EVEN 2

int serial_init(void);

#endif /* INC_SERIAL_H_ */
