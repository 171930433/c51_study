#include "timer.h"
#include <REGX51.H>

TimerCallback t0_callback = 0;
unsigned int t0_rate_counts = 0; // 定时器设置频率,hz
TimerCallback t1_callback = 0;
unsigned int t1_rate_counts = 0; // 定时器设置频率,hz

void TimerInit(unsigned char index, unsigned int rate_hz, TimerCallback fun_ptr)
{
    if (index == 0)
    {
        Timer0Init(rate_hz, fun_ptr);
    }
    else
    {
        Timer1Init(rate_hz, fun_ptr);
    }
}

void Timer0Init(unsigned int rate_hz, TimerCallback fun_ptr)
{
    t0_rate_counts = 1000 / rate_hz;
    // 时钟设置
    TF0 = 0;        // time overflow
    TR0 = 1;        // timer run 
    // 定时器模式
    TMOD &= 0xf0;
    TMOD |= 0x01;
    // 初始计数值
    TL0 = 64535 % 0xff;
    TH0 = 64535 / 0xff;
    // 设置允许中断
    ET0 = 1;
    EA = 1;
    PT0 = 0; // 默认即为最低优先级
    // 设定中断回调函数
    t0_callback = fun_ptr;
}

// 单次进入为1ms
void OnTimer0() interrupt 1
{
    static unsigned int count = 0;
    TF0 = 0;
    TL0 = 64535 % 0xff;
    TH0 = 64535 / 0xff;

    if ((++count % t0_rate_counts) == 0)
    {
        t0_callback();
    }
}

void Timer1Init(unsigned int rate_hz, TimerCallback fun_ptr)
{
    t1_rate_counts = 1000 / rate_hz;
    // 时钟设置
    TF1 = 0;
    TR1 = 1;
    // 定时器模式
    TMOD &= 0x0f;
    TMOD |= 0x10;
    // 初始计数值
    TL1 = 64535 % 0xff;
    TH1 = 64535 / 0xff;
    // 设置允许中断
    ET1 = 1;
    EA = 1;
    PT1 = 0; // 默认即为最低优先级
    // 设定中断回调函数
    t1_callback = fun_ptr;
}

void OnTimer1() interrupt 3
{
    static unsigned int count = 0;
    TF1 = 0;
    TL1 = 64535 % 0xff;
    TH1 = 64535 / 0xff;

    if ((++count % t1_rate_counts) == 0)
    {
        t1_callback();
    }
}