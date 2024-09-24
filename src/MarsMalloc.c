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

// maybe call MarsMem.c?
#include <Windows.h>
#include "MarsCRT.h"

typedef struct HeapLinkListHeader 
{
    enum BLOCK_STATUS
    {
        FREE,
        USED
    } Type;
    size_t HeapSize;
    struct HeapLinkListHeader *Next;
    struct HeapLinkListHeader *Prev;
} *HeapLinkList;

#define HEAP_BLOCK_SIZE sizeof(struct HeapLinkListHeader)
#define VIRT2PHY(ADDR, OFFSET) ((char*)(ADDR) + (OFFSET))

static HeapLinkList Memory = NULL;

void free(void* Mem)
{
    HeapLinkList Start = VIRT2PHY(Mem, HEAP_BLOCK_SIZE);
    if(Start->Type == FREE)
        return;
    
    if(Start->Prev != NULL && Start->Prev->Type == FREE)
    {
        Start->Prev->Next = Start->Next;
        if(Start->Next != NULL)
            Start->Next->Prev = Start->Prev;
        Start->Prev->HeapSize += Start->Next->HeapSize;
    }

    if(Start->Next && Start->Next->Type == FREE)
    {
        Start->HeapSize += Start->Next->HeapSize;
        Start->Next = Start->Next->Next;
    }
}

void* malloc(size_t MemorySize)
{
    void *Result;
    size_t Allocated = 0;

    HeapLinkList Head = Memory;
    while(Allocated < MemorySize)
    {
        if(Head->Type == USED)
        {
            Head = Head->Next;
        }
        if(MemorySize < Head->HeapSize - HEAP_BLOCK_SIZE && MemorySize >= Head->HeapSize - 2 * HEAP_BLOCK_SIZE)
        {
            Head->Type = USED;
        }
        else if (MemorySize >= Head->HeapSize - 2 * HEAP_BLOCK_SIZE)
        {
            HeapLinkList Temp = (HeapLinkList)VIRT2PHY(Head, HEAP_BLOCK_SIZE);
            Temp->Prev = Head;
            Temp->Next = Head->Next;
            Temp->Type = USED;
            Temp->HeapSize = Head->HeapSize - MemorySize;
            
            Head->Next = Temp;
            Head->HeapSize = MemorySize + HEAP_BLOCK_SIZE;
            Head->Type = USED;
            return (void*)VIRT2PHY(Head, HEAP_BLOCK_SIZE);
        }
        
        Head = Head->Next;
    }
    return NULL;
}

int MarsHeapInit()
{
    void *Base = NULL;
    HeapLinkList Header = NULL;
    size_t HeapSize = 1024 * 1024 * 16;

    Base = VirtualAlloc(0, HeapSize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    if(Base == NULL)
    {
        return 1;
    }

    Header = (HeapLinkList) Base;
    Header->HeapSize = HeapSize;
    Header->Type = FREE;
    Header->Next = NULL;
    Header->Prev = NULL;
    Memory = Header;

    return 0;
}