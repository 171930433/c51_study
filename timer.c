#include "timer.h"
#include "lcd1602.h"
#include <REGX51.H>

//TimerSetting g_ts[2] = {0};

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

void Timer0InitRaw()
{
    // 时钟设置
    TF0 = 0; // time overflow
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
    TR0 = 1; // timer run
}

void Timer0Init(unsigned int rate_hz, TimerCallback fun_ptr)
{
    t0_rate_counts = 1000 / rate_hz;
    // 时钟设置
    TF0 = 0; // time overflow
    TR0 = 1; // timer run
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

//void TimerInitWithSetting(TimerSetting *ts)
//{
//    // 保存全局配置
//    g_ts[ts->index_] = *ts;
//    // 设置定时器
//}

// 单次进入为1ms
// void OnTimer0() interrupt 1
// {
//     static unsigned int count = 0;
//     TF0 = 0;
//     TL0 = 64535 % 0xff;
//     TH0 = 64535 / 0xff;

//     if ((++count % t0_rate_counts) == 0)
//     {
//         t0_callback();
//     }
// }

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

// void LED0() { P2_0 = ~P2_0; }
// void LED1() { P2_1 = ~P2_1; }
// void TimerDemo0() // 通过两个定时器使LED0,1以不同频率闪烁
// {
// 	TimerInit(TimerIndex0, 1, LED0);
// 	TimerInit(TimerIndex1, 5, LED1);
// }

// unsigned int number = 0;
// void UpdateData() { ++number; }
// void UpdateView() { LCD_ShowNum(1, 1, number, 5); }
// void TimerDemo1() // 通过两个定时器,一个高频更新数据，一个低频刷新显示
// {
// 	TimerInit(TimerIndex0, 10, UpdateData);
// 	TimerInit(TimerIndex1, 1, UpdateView);
// }