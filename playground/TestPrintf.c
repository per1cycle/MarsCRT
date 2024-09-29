#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


int MarsVfprintf(FILE* Stream, const char* Format, va_list ArgList)
{
    int Flag = 0;

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
            break;
            Format ++;
        }
        
        // TODO: add padding support.

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
    MarsPrintf("hello world\n");
    return 0;
}
