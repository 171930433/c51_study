#include <REGX51.H>
#include "led.h"
#include "independent_keys.h"
#include "nixie_tube.h"
#include "delay.h"
#include "lcd1602.h"
#include "matrix_keys.h"
#include "timer.h"
#include "serial.h"

void ControlLed();	  // 按钮按下点亮led
void ControlLed2();	  // 按钮弹出时点亮led
void NixieOnDemo1();  // 指定index显示数据
void NixieOnDemo2();  // 从第0位开始的ms计时器
void MatrixKeyDemo(); // LCD显示器显示键位
void TimerDemo0();	  // 通过两个定时器使LED0,1以不同频率闪烁
void TimerDemo1();	  // 通过两个定时器,一个高频更新数据，一个低频刷新显示

void main()
{
	LCD_Init();
	UartInit();
	UartSendByte(0x66);
	while (1)
	{
	}
}



void LED0() { P2_0 = ~P2_0; }
void LED1() { P2_1 = ~P2_1; }
void TimerDemo0() // 通过两个定时器使LED0,1以不同频率闪烁
{
	TimerInit(TimerIndex0, 1, LED0);
	TimerInit(TimerIndex1, 5, LED1);
}

unsigned int number = 0;
void UpdateData() { ++number; }
void UpdateView() { LCD_ShowNum(1, 1, number, 5); }
void TimerDemo1() // 通过两个定时器,一个高频更新数据，一个低频刷新显示
{
	TimerInit(TimerIndex0, 10, UpdateData);
	TimerInit(TimerIndex1, 1, UpdateView);
}

void MatrixKeyDemo()
{
	// 需要main函数调用
	// LCD_Init();
	unsigned char key = 0;
	key = ColScanKeyCode2();
	if (key)
	{
		LCD_ShowNum(1, 0, key, 2);
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
