// Final test v0.0.0
#include <stdio.h>

int main(int argc, char** argv)
{
    char c = 'c';
    fwrite(&c, 1, 1, stdout);
    return 0;
}