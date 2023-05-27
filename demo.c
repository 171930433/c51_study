// #include <REGX51.H>
// #include "led.h"
// #include "independent_keys.h"
// #include "nixie_tube.h"
// #include "delay.h"
#include "lcd1602.h"
// #include "matrix_keys.h"
// #include "timer.h"
// #include "serial.h"
// #include "matrix_led.h"
#include "ds1302.h"

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
