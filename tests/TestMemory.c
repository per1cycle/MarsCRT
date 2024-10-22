#include "../src/MarsCRT.h"

int main(int argc, char const *argv[])
{
    // malloc test
    printf("Testing malloc...\n");
    int* a = (int*)malloc(sizeof(int) * 4);
    if (a == NULL) {
        printf("malloc failed!\n");
        return 1;
    }
    for (int i = 0; i < 4; i++) {
        a[i] = i * 10;
    }

    // calloc test
    printf("Testing calloc...\n");
    int* b = (int*)calloc(4, sizeof(int));
    if (b == NULL) {
        printf("calloc failed!\n");
        free(a);
        return 1;
    }
    for (int i = 0; i < 4; i++) {
        printf("b[%d] = %d (should be 0)\n", i, b[i]);  // Expect 0-initialized memory

    }

    // realloc test
    printf("Testing realloc...\n");
    int* c = (int*)realloc(a, sizeof(int) * 8);  // Expand a to hold 8 ints
    if (c == NULL) {
        printf("realloc failed!\n");
        free(b);
        free(a);
        return 1;
    }
    // Assign values to the new space
    for (int i = 4; i < 8; i++) {
        c[i] = i * 10;
    }
    for (int i = 0; i < 8; i++) {
        printf("c[%d] = %d\n", i, c[i]);
    }

    // memcpy test
    printf("Testing memcpy...\n");
    int d[4];
    memcpy(d, c, sizeof(int) * 4);
    for (int i = 0; i < 4; i++) {
        printf("d[%d] = %d\n", i, d[i]);  // Should match c[0] to c[3]
    }

    // memmove test (overlapping memory regions)
    printf("Testing memmove...\n");
    memmove(c + 1, c, sizeof(int) * 7);  // Overlapping move
    for (int i = 0; i < 8; i++) {
        printf("c[%d] = %d\n", i, c[i]);
    }

    // memset test
    printf("Testing memset...\n");
    memset(b, 1, sizeof(int) * 4);  // Fill b with non-zero values
    for (int i = 0; i < 4; i++) {
        printf("b[%d] = %d\n", i, b[i]);
    }

    // memcmp test
    printf("Testing memcmp...\n");
    int cmp_result = memcmp(c, d, sizeof(int) * 4);
    if (cmp_result == 0) {
        printf("c and d are identical in the first 4 ints.\n");
    } else {
        printf("c and d differ in the first 4 ints.\n");
    }

    // free test
    printf("Testing free...\n");
    free(b);
    free(c);  // `c` now holds the original pointer `a` after realloc
    printf("Memory freed successfully.\n");

    return 0;
}
