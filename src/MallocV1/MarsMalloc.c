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

#include "../MarsCRT.h"

#define MAX_SIZE (16 MB)

/**
 * In this version of mars malloc, we use win32 heap operation.
 * Next generation of Malloc, i will consider replace to musl/mimalloc/llvm malloc.
 */
static HANDLE HEAP;

void HeapInit()
{
    HEAP = HeapCreate(HEAP_NO_SERIALIZE, (16 * MB), (32 * MB));
    if(HEAP == NULL)
    {
        ExitProcess(1);
    }
}

void free(void* AllocatedMem)
{
    size_t Result = HeapFree(HEAP, HEAP_NO_SERIALIZE, AllocatedMem);
    if(Result == 0)
    {
        ExitProcess(1);
    }
}

void* malloc(size_t AllocSize)
{
    return HeapAlloc(HEAP, HEAP_ZERO_MEMORY, AllocSize);
}
