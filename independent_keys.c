#include "independent_keys.h"

unsigned char offset[4] = {1, 0, 2, 3};

bit KeyIsPushed(unsigned char numner)
{
	unsigned char n = 0;
    if (numner >= 4)
    {
        return 0;
    }
    n = offset[numner];
    return ((P3 & (1 << n)) >> n) == KEY_PRESSED;
}