#include "ds1302.h"
#include <REGX51.H>

sbit DS1302_SCLK = P3 ^ 6;
sbit DS1302_IO = P3 ^ 4;
sbit DS1302_CE = P3 ^ 5;

unsigned char Bcd2Hex(unsigned char bcd)
{
    return bcd / 16 * 10 + bcd % 16;
}

unsigned char Hex2Bcd(unsigned char hex)
{
    return hex / 10 * 16 + hex % 10;
}

void DS1302_Init()
{
    DS1302_CE = 0;
    DS1302_SCLK = 0;
}

unsigned char DS1302_ReadByte(unsigned char cmd)
{
    unsigned char i = 0;
    unsigned char t0 = 0;
    DS1302_CE = 1;
    cmd |= 0x01;
    // write read command
    for (i = 0; i < 8; ++i)
    {
        DS1302_IO = cmd & (0x01 << i);
        DS1302_SCLK = 0;
        DS1302_SCLK = 1;
    }
    // read byte
    for (i = 0; i < 8; ++i)
    {
        DS1302_SCLK = 1;
        DS1302_SCLK = 0;
        if (DS1302_IO)
        {
            t0 |= (0x01 << i);
        }
    }

    DS1302_CE = 0;
    DS1302_IO = 0;
    return Bcd2Hex(t0);
}

void DS1302_WriteByte(unsigned char cmd, unsigned char t0)
{
    unsigned char i = 0;
    DS1302_CE = 1;
    t0 = Hex2Bcd(t0);
    // write read command
    for (i = 0; i < 8; ++i)
    {
        DS1302_IO = cmd & (0x01 << i);
        DS1302_SCLK = 1;
        DS1302_SCLK = 0;
    }
    // read byte
    for (i = 0; i < 8; ++i)
    {
        DS1302_IO = t0 & (0x01 << i);
        DS1302_SCLK = 1;
        DS1302_SCLK = 0;
    }

    DS1302_CE = 0;
}

void DS1302_ReadTime(unsigned char* time)
{
    time[0] = DS1302_ReadByte(YEAR);
    time[1] = DS1302_ReadByte(MONTH);
    time[2] = DS1302_ReadByte(DATE);
    time[3] = DS1302_ReadByte(HOUR);
    time[4] = DS1302_ReadByte(MIN);
    time[5] = DS1302_ReadByte(SEC);
}

void DS1302_WriteTime(unsigned char* time)
{
    DS1302_WriteByte(WP, 0x00);
    DS1302_WriteByte(YEAR, time[0]);
    DS1302_WriteByte(MONTH, time[1]);
    DS1302_WriteByte(DATE, time[2]);
    DS1302_WriteByte(HOUR, time[3]);
    DS1302_WriteByte(MIN, time[4]);
    DS1302_WriteByte(SEC, time[5]);
    DS1302_WriteByte(WP, 0x80);
}
