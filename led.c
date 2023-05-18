#include "led.h"

void LightingLedN(unsigned char number)
{
    if (number >= 8)
    {
        return;
    }
    P2 &= (255 - (1 << number));
}

void TurnOffLenN(unsigned char number)
{
    if (number >= 8)
    {
        return;
    }
    P2 |= (1 << number);
}

void ReverseLenN(unsigned char number)
{
    if (number >= 8)
    {
        return;
    }
    P2 ^= (1 << number);
}

