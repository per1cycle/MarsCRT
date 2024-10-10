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

// Common defination 
#include <Windows.h>

#define size_t unsigned long
#define NULL (void*)(0)
#define true    1
#define false   0
#define bool    int

// Defination for io
#define EOF     (-1)
#define FILE    int
#define stdin   ((FILE*)GetStdHandle(STD_IN_HANDLE))
#define stdout  ((FILE*)GetStdHandle(STD_OUTPUT_HANDLE))
#define stderr  ((FILE*)GetStdHandle(STD_ERROR_HANDLE))

// Config defination.
#define __MARS

// MarsString.c
#define string (char*)
char* itoa(int, char*);
size_t _strlen(char*); // TODO: fix native strlen.
int strcmp(char*, char*);

// MarsIO
int fwrite(const void*, size_t, size_t, FILE* );
int fputc(char, FILE*);
int fputs(char*, FILE*);
int putc(char);
int puts(char*);

// MarsPrintf
int vfprintf(FILE*, const char*, va_list);
int printf(const char*, ...);

// MarsMalloc
int MarsHeapInit();
int MarsIOInit();

// util definition
#define UNUSED_PARAM(x) ((x))

// global definition
#define B           (1)
#define KB          (1024 * B)
#define MB          (1024 * KB)
#define HEAP_SIZE   (16 MB)

