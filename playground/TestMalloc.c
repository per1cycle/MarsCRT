#pragma once

#include <Windows.h>

#define size_t unsigned long
#define NULL (void*)(0)

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

HeapLinkList Memory = NULL;

void free(void* Mem)
{
    HeapLinkList Start = VIRT2PHY(Mem, -HEAP_BLOCK_SIZE);
    if(Start->Type != USED)
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
    while(Head)
    {
        if(Head->Type == USED)
        {
            Head = Head->Next;
        }
        if(MemorySize < Head->HeapSize - HEAP_BLOCK_SIZE && MemorySize >= Head->HeapSize - 2 * HEAP_BLOCK_SIZE)
        {
            Head->Type = USED;
        }
        else if (MemorySize <= Head->HeapSize - 2 * HEAP_BLOCK_SIZE)
        {
            HeapLinkList Temp = (HeapLinkList)VIRT2PHY(Head, HEAP_BLOCK_SIZE);
            Temp->Prev = Head;
            Temp->Next = Head->Next;
            Temp->Type = USED;
            Temp->HeapSize = Head->HeapSize - MemorySize + HEAP_BLOCK_SIZE;
            
            Head->Next = Temp;
            Head->HeapSize = MemorySize + HEAP_BLOCK_SIZE;
            Head->Type = USED;
            return (void*)VIRT2PHY(Head, HEAP_BLOCK_SIZE);
        }
        
        Head = Head->Next;
    }
    return NULL;
}

int HeapInit()
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

int main(int argc, char const *argv[])
{
    HeapInit();
    void* mem = malloc(10);
    if(mem != NULL)
    {
        int x = 1;
    }
    else 
    {
        int y = 2;
    }

    free(mem);
    return 0;
}
