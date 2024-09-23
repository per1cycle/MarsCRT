// Final test v0.0.0
#include "../src/MarsCRT.h"

int myfwrite(const void* Buffer, size_t Size, size_t Count, FILE* Stream)
{
    size_t Write = 0;
    if(!WriteFile((HANDLE)Stream, Buffer, Size * Count, &Write, NULL))
    {
        return 0;
    }
    return Write;

}

int main(int argc, char** argv)
{
    char c = 'c';
    myfwrite(&c, 1, 1, 1);
    return 0;
}