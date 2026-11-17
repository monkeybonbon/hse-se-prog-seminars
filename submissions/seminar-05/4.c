#include <stdio.h>

int main() {
    int b[4][5];
    int* p = &b[2][1], * q = &b[3][4];

    printf("a) q - (int *)b = %td\n", q - (int*)b);
    printf("b) p - (int *)b = %td\n", p - (int*)b);
    printf("c) p - q = %td\n", p - q);

    return 0;
}