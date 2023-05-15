#include "matrix_keys.h"
#include "delay.h"
#include <REGX51.H>

unsigned char RowScanKeyCode()
{
    // row0
    P1 = 0xff;
    P1_7 = 0;
    if(P1_3 == 0){Delay(20); while(P1_3 == 0); Delay(20); return 0; }
    if(P1_2 == 0){Delay(20); while(P1_2 == 0); Delay(20); return 1; }
    if(P1_1 == 0){Delay(20); while(P1_1 == 0); Delay(20); return 2; }
    if(P1_0 == 0){Delay(20); while(P1_0 == 0); Delay(20); return 3; }
    // row1 
    P1 = 0xff;
    P1_6 = 0;
    if(P1_3 == 0){Delay(20); while(P1_3 == 0); Delay(20); return 0 + 4; }
    if(P1_2 == 0){Delay(20); while(P1_2 == 0); Delay(20); return 1 + 4; }
    if(P1_1 == 0){Delay(20); while(P1_1 == 0); Delay(20); return 2 + 4; }
    if(P1_0 == 0){Delay(20); while(P1_0 == 0); Delay(20); return 3 + 4; }
    // row2
    P1 = 0xff;
    P1_5 = 0;
    if(P1_3 == 0){Delay(20); while(P1_3 == 0); Delay(20); return 0 + 8; }
    if(P1_2 == 0){Delay(20); while(P1_2 == 0); Delay(20); return 1 + 8; }
    if(P1_1 == 0){Delay(20); while(P1_1 == 0); Delay(20); return 2 + 8; }
    if(P1_0 == 0){Delay(20); while(P1_0 == 0); Delay(20); return 3 + 8; }
    // row3
    P1 = 0xff;
    P1_4 = 0;
    if(P1_3 == 0){Delay(20); while(P1_3 == 0); Delay(20); return 0 + 12; }
    if(P1_2 == 0){Delay(20); while(P1_2 == 0); Delay(20); return 1 + 12; }
    if(P1_1 == 0){Delay(20); while(P1_1 == 0); Delay(20); return 2 + 12; }
    if(P1_0 == 0){Delay(20); while(P1_0 == 0); Delay(20); return 3 + 12; }

    return 0;
}

unsigned char RowScanKeyCode2()
{
    unsigned char i, j;
    for (i = 0; i < 4; ++i)
    {
        P1 = 0xff;
        P1 &= (0xff - (1 << (7 - i)));
        for (j = 0; j < 4; ++j)
        {
            if((P1&(1 << (3-j)))>>(3-j) == 0){ 
                Delay(20);
                while((P1&(1 << (3-j)))>>(3-j) == 0);
                Delay(20);
                return i * 4 + j + 1;
            }
        }
    }
    return 0;
}


unsigned char ColScanKeyCode()
{
    P1 = 0xff;
    // row0
    P1_3 = 0;
    if(P1_7 == 0){Delay(20); while(P1_7 == 0); Delay(20); return 1; }
    if(P1_6 == 0){Delay(20); while(P1_6 == 0); Delay(20); return 5; }
    if(P1_5 == 0){Delay(20); while(P1_5 == 0); Delay(20); return 9; }
    if(P1_4 == 0){Delay(20); while(P1_4 == 0); Delay(20); return 13; }
    // row1 
    P1 = 0xff;
    P1_2 = 0;
    if(P1_7 == 0){Delay(20); while(P1_7 == 0); Delay(20); return 2; }
    if(P1_6 == 0){Delay(20); while(P1_6 == 0); Delay(20); return 6; }
    if(P1_5 == 0){Delay(20); while(P1_5 == 0); Delay(20); return 10; }
    if(P1_4 == 0){Delay(20); while(P1_4 == 0); Delay(20); return 14; }
    // row2
    P1 = 0xff;
    P1_1 = 0;
    if(P1_7 == 0){Delay(20); while(P1_7 == 0); Delay(20); return 3; }
    if(P1_6 == 0){Delay(20); while(P1_6 == 0); Delay(20); return 7; }
    if(P1_5 == 0){Delay(20); while(P1_5 == 0); Delay(20); return 11; }
    if(P1_4 == 0){Delay(20); while(P1_4 == 0); Delay(20); return 15; }
    // row3
    P1 = 0xff;
    P1_0 = 0;
    if(P1_7 == 0){Delay(20); while(P1_7 == 0); Delay(20); return 4; }
    if(P1_6 == 0){Delay(20); while(P1_6 == 0); Delay(20); return 8; }
    if(P1_5 == 0){Delay(20); while(P1_5 == 0); Delay(20); return 12; }
    if(P1_4 == 0){Delay(20); while(P1_4 == 0); Delay(20); return 16; }

    return 0;
}

unsigned char ColScanKeyCode2()
{
    unsigned char i, j;
    for (i = 0; i < 4; ++i)
    {
        P1 = 0xff;
        P1 &= (0xff - (1 << (3 - i)));
        for (j = 0; j < 4; ++j)
        {
            if((P1&(1 << (7-j)))>>(7-j) == 0){ 
                Delay(20);
                while((P1&(1 << (7-j)))>>(7-j) == 0);
                Delay(20);
                return j * 4 + i + 1;
            }
        }
    }
    return 0;
}