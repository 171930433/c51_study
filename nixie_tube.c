#include "nixie_tube.h"
#include "delay.h"
#include <math.h>
#include <REGX51.H>

unsigned int codes[10] = {~0xC0, ~0xF9, ~0xA4, ~0xB0, ~0x99, ~0x92, ~0x82, ~0xF8, ~0x80, ~0x90};

void NixieOn(unsigned char index, unsigned char n)
{
    switch (index)
    {
    case 0:
        P2_4 = 0, P2_3 = 0, P2_2 = 0;
        break;
    case 1:
        P2_4 = 0, P2_3 = 0, P2_2 = 1;
        break;
    case 2:
        P2_4 = 0, P2_3 = 1, P2_2 = 0;
        break;
    case 3:
        P2_4 = 0, P2_3 = 1, P2_2 = 1;
        break;
    case 4:
        P2_4 = 1, P2_3 = 0, P2_2 = 0;
        break;
    case 5:
        P2_4 = 1, P2_3 = 0, P2_2 = 1;
        break;
    case 6:
        P2_4 = 1, P2_3 = 1, P2_2 = 0;
        break;
    case 7:
        P2_4 = 1, P2_3 = 1, P2_2 = 1;
        break;
    default:
        return;
    }

    P0 = codes[n]; // 位选
    Delay(1);      // 持续显示
    P0 = 0x00;     // 位选清空
}

void NixieOnNumber(unsigned int n)
{
    unsigned char counts = ceil(log10(n));
    unsigned char i = 0;

    for (i = 0; i < counts; ++i)
    {
        NixieOn(i, n % 10);
        n /= 10;
    }
}
