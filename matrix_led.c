#include "matrix_led.h"
#include <REGX51.H>
#include "delay.h"

sbit RCK = P3 ^ 5; // register clock, 8位输出
sbit SCK = P3 ^ 6; // serial clock 串行时钟, 给1向下一位
sbit SER = P3 ^ 4; // serial 串行,待赋值寄存器

void _74HC595_Init()
{
    SCK = 0;
    RCK = 0;
}

void MatrixLedInit()
{
    _74HC595_Init();
}

void _74HC595_WriteBite(unsigned char index)
{
    unsigned char i = 0;
    for (i = 0; i < 8; ++i)
    {
        SER = index & (0x80 >> i); // 移入74hc595 寄存器时钟位
        SCK = 1;
        SCK = 0;
    }
    RCK = 1;
    RCK = 0;
}

void LightMatrixLedColumn(unsigned char col, unsigned char index)
{
    // 位选
    _74HC595_WriteBite(index);
    P0 = ~(0x80 >> col); // 7-col位置零
    Delay(1);
    P0 = 0xff; // 消影
}

void MatrixLedDemo()
{
    LightMatrixLedColumn(0, 0xff);
    LightMatrixLedColumn(1, 0x0A);
    LightMatrixLedColumn(2, 0xA0);
    LightMatrixLedColumn(3, 0x05);
    LightMatrixLedColumn(4, 0x50);
    LightMatrixLedColumn(5, 0xC3);
    LightMatrixLedColumn(6, 0x3C);
    LightMatrixLedColumn(7, 0x18);
}
