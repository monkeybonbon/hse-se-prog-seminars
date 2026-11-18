#include <stdio.h>

int main(void) {
    int a, b;

    scanf("%d %d", &a, &b);
    int abs_a = a >= 0 ? a : -a;
    int max = a > b ? a:b;

    printf("%d\n", abs_a);
    printf("%d\n", max);

    return 0;
}