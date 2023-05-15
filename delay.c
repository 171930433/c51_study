#include "delay.h"
#include <intrins.h>
void Delay(unsigned int ms)
{
    unsigned char i, j;
    _nop_();
    while (ms--)
    {
        i = 2;
        j = 199;
        do
        {
            while (--j);
        } while (--i);
    }
}