#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define bool int
#define true 1
#define false 0

char *MarsAtoi(int n, char *buf)
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
        cnt ++;
        i /= 10;

    } while (i);

    if (neg)
    {
        Result[cnt] = '-';
        cnt ++;
    }

    for (i = 0; i < cnt / 2; i++)
    {
        char Temp;
        Temp = Result[i];
        Result[i] = Result[cnt - i - 1];
        Result[cnt - i - 1] = Temp;
    }
    Result[cnt] = '\0';
    return Result;
}

size_t MarsStrlen(char* str)
{
    size_t Length = 0;
    for(;str[Length] != '\0'; Length ++);
    return Length;
}


int main(int argc, char const *argv[])
{
    char Buffer[1024];
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        int TestNum = rand();
        int flag = rand() % 2 ? 1: -1;
        TestNum *= flag;
        
        printf("[INFO]: My atoi(%d): %s\n", TestNum, MarsAtoi(TestNum, Buffer));

    }

    char* s = "Hello wrold";
    printf("[INFO]: My strlen(%s): %d\n", s, MarsStrlen(s));


    return 0;
}
