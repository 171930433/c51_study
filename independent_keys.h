#ifndef INDEPENDENT_KEYS_H
#define INDEPENDENT_KEYS_H

#include "led.h"
#include <REGX51.H>

#define KEY_PRESSED 0

bit KeyIsPushed(unsigned char number);
bit KeyIsPoped(unsigned char number);


// demo
void ControlLed();	  // 按钮按下点亮led
void ControlLed2();	  // 按钮弹出时点亮led

#endif