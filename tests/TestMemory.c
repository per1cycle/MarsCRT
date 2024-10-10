#include "../src/MarsCRT.h"

int main(int argc, char const *argv[])
{
    int* a = (int* )malloc(sizeof(int) * 4);
    free((void*) a);
    log("Hello world");
    return 0;
}
