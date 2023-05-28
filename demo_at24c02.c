#include "at24c02.h"
#include "lcd1602.h"
#include "delay.h"

void main()
{
	unsigned char num = 0;

	LCD_Init();

	AT24C02_WriteByte(0, 0xa0);
	Delay(5);
	num = AT24C02_ReadByte(0);

	LCD_ShowNum(1, 1, num, 3);

	while (1)
	{
	}
}
