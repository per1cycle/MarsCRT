// Final test v0.0.0
#include "../src/MarsCRT.h"

int main(int argc, char** argv)
{
    char buffer[1024];
    char i = '2';
    fputc(i, stdout);

    char* str = itoa(argc, buffer);
    fputc(&str[0], stdout);
    
    return 0;
}