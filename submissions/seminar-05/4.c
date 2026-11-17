#include <stdio.h>

int main(void) {
    int b[4][5]; 
    int *p = &b[2][1], *q = &b[3][4];
    printf("%d \n", q - (int *)b);
    printf("%d \n", p - (int *)b);
    printf("%d \n", p - q);

    return 0;
}