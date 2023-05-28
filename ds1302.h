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


/** 时间demo
 * 
 *
void main()
{
	unsigned char t1[6] = {23, 5, 24, 7, 23, 58};
	unsigned char t2[6] = {0};
	LCD_Init();
	DS1302_Init();

	LCD_ShowString(1, 1, "  -  -  ");
	LCD_ShowString(2, 1, "  :  :  ");
	DS1302_WriteTime(t1);

	while (1)
	{

		DS1302_ReadTime(t2);

		LCD_ShowNum(1, 1, t2[0], 2);
		LCD_ShowNum(1, 4, t2[1], 2);
		LCD_ShowNum(1, 7, t2[2], 2);
		LCD_ShowNum(2, 1, t2[3], 2);
		LCD_ShowNum(2, 4, t2[4], 2);
		LCD_ShowNum(2, 7, t2[5], 2);
	}
}

 * 
 * 
*/