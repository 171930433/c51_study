#ifndef BUZEER_H
#define BUZZER_H
// #include <REGX52.H>

// 播放速度，值为四分音符的时长(ms)
#define SPEED 500

// 索引与频率对照表
extern unsigned int FreqTable[];
// 乐谱
extern unsigned char code Music[];

extern unsigned char FreqSelect;
extern unsigned char MusicSelect;

void BuzzerReverseLoop();

#endif
