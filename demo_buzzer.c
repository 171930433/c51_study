#include <REGX51.H>
// #include "led.h"
// #include "independent_keys.h"
// #include "nixie_tube.h"
#include "delay.h"
// #include "lcd1602.h"
// #include "matrix_keys.h"
#include "timer.h"
// #include "serial.h"
// #include "matrix_led.h"
// #include "ds1302.h"

#include "buzzer.h"

void main()
{
	unsigned int i = 0;
	// TimerInit(TimerIndex0, 1000, BuzzerReverseLoop);
	Timer0InitRaw();

	while (1)
	{
		if (Music[MusicSelect] != 0xFF) // 如果不是停止标志位
		{
			FreqSelect = Music[MusicSelect]; // 选择音符对应的频率
			MusicSelect++;
			Delay(SPEED / 4 * Music[MusicSelect]); // 选择音符对应的时值
			MusicSelect++;
			TR0 = 0;
			Delay(5); // 音符间短暂停顿
			TR0 = 1;
		}
		else // 如果是停止标志位
		{
			TR0 = 0;
			while (1)
				;
		}

	}
}

void OnTimer00() interrupt 1
{
	BuzzerReverseLoop();
}