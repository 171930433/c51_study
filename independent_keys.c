#include "independent_keys.h"
#include "delay.h"

unsigned char offset[4] = {1, 0, 2, 3};

// 按下按钮即为真
bit KeyIsPushed(unsigned char number)
{
    unsigned char n = 0;
    if (number >= 4)
    {
        return 0;
    }
    n = offset[number];
    return ((P3 & (1 << n)) >> n) == KEY_PRESSED;
}

// 按键防抖功能,按钮弹片释放,且完全松开后为真
bit KeyIsPoped(unsigned char number)
{
    if (KeyIsPushed(number))
    {
        Delay(20);
        while(KeyIsPushed(number));
        Delay(20);
        return 1;
    }
    else
    {
        return 0;
    }
}
