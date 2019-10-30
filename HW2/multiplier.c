//#include<stdio.h>
void _start()
{
    int mul1 = -1;
    int mul2 = -2;
    int result = 0;

    for(int i=0;i<32;i++)
    {
        if((mul2 >> i) & 0x1)
            result = result + (mul1 << i);              
    }

    volatile  int* tx = (volatile int*) 0x40002000;
    *tx = result;
}

