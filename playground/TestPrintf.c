#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * 
 * MarsVfprintf support 
 */
int MarsVfprintf(FILE* Stream, const char* Format, va_list ArgList)
{
    int Flag = 0;
    char Buffer[1024];

    for(;*Format;)
    {
        if( *Format != '%')
        {
            putc(*Format, Stream);
            Format ++;
            continue;
        }

        else 
        {
            Format ++;
        }
        
        // TODO: add padding support.
        
        // output:
        switch (*Format)
        {
        case 'd':
            *Format ++;
            int Value = va_arg(ArgList, int);
            puts(itoa(Value, Buffer, 10));
            break;
        
        default:
            break;
        }
    }
}

int MarsPrintf(const char* Format, ...)
{
    va_list ArgList;
    va_start(ArgList, Format);
    int Result = MarsVfprintf(stdout, Format, ArgList);
    va_end(ArgList);
    return Result;
}

int main(int argc, char const *argv[])
{
    MarsPrintf("hello %d world\n", 'c');
    return 0;
}
