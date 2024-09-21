#include "MarsCRT.h"

/**
 * convert decimal to char*
 */
char* itoa(int n, char*buf)
{
    char Result[1024];
    int i = n;
    int cnt = 0;
    bool neg = false;
    if (i < 0)
    {
        neg = true;
        i = -i;
    }
    do
    {
        int Temp = i % 10;
        Result[cnt] = '0' + Temp;
        buf[cnt] = '0' + Temp;
        cnt ++;
        i /= 10;

    } while (i);

    if (neg)
    {
        Result[cnt] = '-';
        buf[cnt] = '-';
        cnt ++;
    }

    for (i = 0; i < cnt / 2; i++)
    {
        char Temp;
        Temp = Result[i];
        Result[i] = Result[cnt - i - 1];
        Result[cnt - i - 1] = Temp;

        buf[i] = Result[i];
        buf[cnt - i - 1] = Result[cnt - i - 1];
    }
    
    Result[cnt] = '\0';
    buf[cnt] = '\0';
    
    return Result;
}