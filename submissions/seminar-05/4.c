#include <stdio.h>

int main(void) {
    int b[4][5];
    int *p = &b[2][1];
    int *q = &b[3][4];

    printf("%ld\n", q - (int *)b); // 19
    printf("%ld\n", p - (int *)b); // 11
    printf("%ld\n", p - q);        // -8

    return 0;
}
