#include "delay.h"

void Delay(unit8 ms)
{
    unsigned char i, j;
    while (ms--)
    {
        i = 2;
        j = 239;
        do
        {
            while (--j)
                ;
        } while (--i);
    }
}