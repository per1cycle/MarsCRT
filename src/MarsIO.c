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

// alter for stdio
#include "MarsCRT.h"
#include <Windows.h>

int MarsIOInit()
{
    return 1;
}

int fopen()
{

}

int fclose(FILE* File)
{
    CloseHandle((HANDLE)File);
}

int fread()
{

}

int fwrite(const void* Buffer, size_t Size, size_t Count, FILE* Stream)
{
    size_t Write = 0;
    // just out put to stdout
    if(!WriteFile((HANDLE)Stream, Buffer, Size * Count, &Write, NULL))
    {
        return 0;
    }
    return Write;
}

