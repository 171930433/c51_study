#include <REGX51.H>
// #include "led.h"
// #include "independent_keys.h"
// #include "nixie_tube.h"
#include "delay.h"
#include "lcd1602.h"
// #include "matrix_keys.h"
// #include "timer.h"
// #include "serial.h"
#include "matrix_led.h"




void main()
{
	// LCD_Init();

	MatrixLedInit();
	while (1)
	{
		LightMatrixLedColumn(0, 0xff);
		LightMatrixLedColumn(1, 0x0A);
		LightMatrixLedColumn(2, 0xA0);
		LightMatrixLedColumn(3, 0x05);
		LightMatrixLedColumn(4, 0x50);
	}
}







