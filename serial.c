#include "serial.h"
#include <REGX51.H>

void UartInit() // 4800bps@11.0592MHz
{
    SCON = 0x50;  // 8位UART,波特率可变
    PCON |= 0x80; // 波特率加倍
    // 定时器模式
    TMOD &= 0x0f;
    TMOD |= 0x20;
    // T1 时钟
    TL1 = 0xf4;
    TH1 = 0xf4;
    TR1 = 1; // timer run
    // 中断, 默认最低优先级
    ES = 1; // enable serial?
    EA = 1; // enable all
}

void UartSendByte(unsigned char byte0)
{
    SBUF = byte0;
}

void Callback() interrupt 4
{
    // 读取完毕
    if (RI == 1)
    {
        P2_0 = ~P2_0;
        // 读取SBUF
        RI = 0;
    }
    // 发送完毕
    if (TI == 1)
    {
        TI = 0; // 软复位
    }
}