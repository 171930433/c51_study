#ifndef DS1302_H
#define DS1302_H

typedef enum Command_t
{
    SEC = 0X80,
    MIN = 0X82,
    HOUR = 0X84,
    DATE = 0X86,
    MONTH = 0X88,
    DAY = 0X8a,
    YEAR = 0X8c,
    WP = 0x8e
} Command;

void DS1302_Init();
void DS1302_ReadTime(unsigned char *time);
void DS1302_WriteTime(unsigned char *time);
//
void DS1302_WriteByte(unsigned char cmd, unsigned char t0);
unsigned char DS1302_ReadByte(unsigned char cmd);

#endif