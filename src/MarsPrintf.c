// The MIT License (MIT)

// Copyright (c) 2024 per1cycle

//  Permission is hereby granted, free of charge, to any person obtaining a
//  copy of this software and associated documentation files (the "Software"),
//  to deal in the Software without restriction, including without limitation
//  the rights to use, copy, modify, merge, publish, distribute, sublicense,
//  and/or sell copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
//  DEALINGS IN THE SOFTWARE.

#include "MarsCRT.h"

int fputc(char Char, FILE* Stream)
{
    if(fwrite(&Char, 1, 1, Stream) != 1)
    {
        return EOF;
    }
    return 0;
}

int fputs(char* String, FILE* Stream)
{
    size_t Length = _strlen(String);
    if(fwrite(String, 1, Length, stdout) != Length)
    {
        return EOF;
    }
    return 0;
}

int putc(char Char)
{
    if(fputc(Char, stdout) < 0)
    {
        return EOF;
    }
    return 0;
}

int puts(char* String)
{
    if(fputs(String, stdout) < 0)
    {
        return EOF;
    }
    return 0;
}

int vfprintf(FILE* Stream, const char* Format, va_list ArgList)
{
    int Flag = 0;
    char Buffer[1024];

    for(;*Format;)
    {
        if( *Format != '%')
        {
            putc(*Format);
            Format ++;
            continue;
        }

        else 
        {
            Format ++;
        }
        
        // TODO: add padding support.
        
        // evaluate width
        switch (*Format)
        {
        case 'd':
            *Format ++;
            int iValue = va_arg(ArgList, int);
            puts(itoa(iValue, Buffer));
            break;
        case 'c':
            *Format ++;
            char cValue = va_arg(ArgList, char);
            putc(cValue);
            break;
        case 's':
            *Format ++;
            char* sValue = va_arg(ArgList, const char*);
            puts(sValue);
            break;
        default:
            break;
        }
    }

}

int printf(const char* Format, ...)
{
    va_list ArgList;
    va_start(ArgList, Format);

    return vfprintf(stdout, Format, ArgList);
}

#ifdef DEBUG_PRINTF
int log(const char* Format, ...)
{
    printf("[INFO]: ");
    va_list ArgList;
    va_start(ArgList, Format);
    vfprintf(stdout, Format, ArgList);
    printf("\n");
}

#endif