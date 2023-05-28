#ifndef TIMER_H
#define TIMER_H

#define TimerIndex0 0
#define TimerIndex1 1

typedef void (*TimerCallback)(void);
// 定时器设置
//typedef struct TimerSetting_t
//{
//    unsigned char index_;
//    unsigned int rate_hz_;     // 调用频率 (0,1000]
//    TimerCallback cbk_;        // 指定频率回调的函数
//    unsigned int duration_ms_; // 持续时间 ms
//    TimerCallback end_cbk_;    // 指定频率回调的函数
//    //
//    unsigned int frame_counts; // 单次溢出1ms

//}
//TimerSetting; 

//void TimerInitWithSetting(TimerSetting* ts);

// old
void Timer0InitRaw();
void TimerInit(unsigned char index, unsigned int rate_hz, TimerCallback fun_ptr);
void Timer0Init(unsigned int rate_hz, TimerCallback fun_ptr);
void Timer1Init(unsigned int rate_hz, TimerCallback fun_ptr);

// demo
void TimerDemo0(); // 通过两个定时器使LED0,1以不同频率闪烁
void TimerDemo1(); // 通过两个定时器,一个高频更新数据，一个低频刷新显示
//

#endif