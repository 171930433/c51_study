#ifndef DELAY_H
#define DELAY_H

void Delay(unsigned int ms)
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



#endif