#include "../src/MarsCRT.h"

int main(int argc, char const *argv[])
{
    printf("Hello world\n");
    printf("[INFO] this is a test for int: %d + %d = %d\n", 1, 2, 1 + 2);
    printf("[INFO] this is a test for char: %c\n", 'f');
    printf("[INFO] this is a test for string: %s\n", "hello");
    printf("[INFO] this is a test for mixed: int: %d, char: %c, string: %s\n", 8, 'c', "hello");
    return 0;
}
