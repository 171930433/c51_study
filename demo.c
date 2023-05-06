#include <REGX51.H>
#include "led.h"
#include "independent_keys.h"
#include "delay.h"

void ControlLed();

void main()
{
	unsigned char offset[4] = {1, 0, 2, 3};

	while (1)
	{
		ControlLed();
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
