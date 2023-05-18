#ifndef NIXIE_TUBE_H
#define NIXIE_TUBE_H

void NixieOn(unsigned char index, unsigned char n);
void NixieOnNumber(unsigned int n);

// demo
void NixieOnDemo1();  // 指定index显示数据
void NixieOnDemo2();  // 从第0位开始的ms计时器

#endif