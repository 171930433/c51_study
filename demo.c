#include <REGX51.H>
#include "led.h"
#include "independent_keys.h"
#include "delay.h"

void ControlLed();	// 按钮按下点亮led
void ControlLed2(); // 按钮弹出时点亮led

void main()
{
	while (1)
	{
		ControlLed2();
	}
}

void ControlLed2()
{

	int i = 0;
	for (i = 0; i < 4; ++i)
	{
		if (KeyIsPoped(i))
		{
			ReverseLenN(i);
		}
	}
}

void ControlLed()
{

	int i = 0;
	for (i = 0; i < 4; ++i)
	{
		if (KeyIsPushed(i))
		{
			LightingLedN(i);
		}
		else
		{
			TurnOffLenN(i);
		}
	}
}
