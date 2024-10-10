#include "../src/MarsCRT.h"

int main(int argc, char const *argv[])
{
    int* a = (int*)malloc(sizeof(int) * 4);
    free(a);
    

    return 0;
}
