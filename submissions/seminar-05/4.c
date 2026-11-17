#include <stdio.h>

int main(void)
{
    int b[4][5];
    int *p = &b[2][1], *q = &b[3][4];
    printf("%td \n", q - (int *)b);
    printf("%td \n", p - (int *)b);
    printf("%td \n", p - q);
    // a = 19
    // b = 11
    // в = -8
    return 0;
}