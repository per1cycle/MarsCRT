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

#pragma once
#include "MarsCRT.h"
/**
 * convert decimal to char*
 */
char* itoa(int Number, char* Buffer)
{
    char Result[1024];
    int i = Number;
    int Count = 0;
    bool Neg = false;
    if (i < 0)
    {
        Neg = true;
        i = -i;
    }
    do
    {
        int Temp = i % 10;
        Result[Count] = '0' + Temp;
        Buffer[Count] = '0' + Temp;
        Count ++;
        i /= 10;

    } while (i);

    if (Neg)
    {
        Result[Count] = '-';
        Buffer[Count] = '-';
        Count ++;
    }

    for (i = 0; i < Count / 2; i++)
    {
        char Temp;
        Temp = Result[i];
        Result[i] = Result[Count - i - 1];
        Result[Count - i - 1] = Temp;

        Buffer[i] = Result[i];
        Buffer[Count - i - 1] = Result[Count - i - 1];
    }
    
    Result[Count] = '\0';
    Buffer[Count] = '\0';
    
    return Result;
}

size_t _strlen(char* Char)
{
    size_t Length = 0;
    for(;Char[Length]; Length ++);
    return Length;
}

/**
 * if s1 > s2?
 */
int strcmp(char* S1, char* S2)
{
    size_t Length1 = _strlen(S1);
    size_t Length2 = _strlen(S2);
    size_t i, j;
    size_t Iter = min(Length1, Length2);
    for(i = 0, j = 0; i < Iter && j < Iter; i ++, j ++)
    {
        if(S1[i] != S2[i])
            return S1[i] > S2[i];
    }
    return 0;
}