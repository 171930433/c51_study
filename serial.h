#ifndef SERIAL_H
#define SERIAL_H

typedef void (*SerialCallback)(void);
void UartInit(); // 4800bps@12.000MHz
void UartSendByte(unsigned char byte0);

#endif