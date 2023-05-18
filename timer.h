#ifndef TIMER_H
#define TIMER_H

#define TimerIndex0 0
#define TimerIndex1 1
typedef void (*TimerCallback)(void);
void TimerInit(unsigned char index, unsigned int rate_hz, TimerCallback fun_ptr);
void Timer0Init(unsigned int rate_hz, TimerCallback fun_ptr);
void Timer1Init(unsigned int rate_hz, TimerCallback fun_ptr);

// demo
void TimerDemo0(); // 通过两个定时器使LED0,1以不同频率闪烁
void TimerDemo1(); // 通过两个定时器,一个高频更新数据，一个低频刷新显示

#endif