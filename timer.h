#ifndef TIMER_H
#define TIMER_H


#define TimerIndex0 0
#define TimerIndex1 1
typedef void (*TimerCallback)(void);
void TimerInit(unsigned char index, unsigned int rate_hz, TimerCallback fun_ptr);
void Timer0Init(unsigned int rate_hz, TimerCallback fun_ptr);
void Timer1Init(unsigned int rate_hz, TimerCallback fun_ptr);

#endif