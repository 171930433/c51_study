#include <REGX51.H>
#include "led.h"
#include "independent_keys.h"
#include "nixie_tube.h"
#include "delay.h"

void ControlLed();	 // 按钮按下点亮led
void ControlLed2();	 // 按钮弹出时点亮led
void NixieOnDemo1(); // 指定index显示数据
void NixieOnDemo2(); // 从第0位开始的ms计时器

void main()
{
	int i = 0;
	int j = 0;
	while (1)
	{
		NixieOnDemo2();
	}
}

void NixieOnDemo2()
{
	int i = 0;
	for (i = 0; i < 1e8; ++i)
	{
		NixieOnNumber(i);
		Delay(1);
	}
}

void NixieOnDemo1()
{
	NixieOn(4, 8);
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
