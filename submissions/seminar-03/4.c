#include <stdio.h>

int main(void) {
    int a;
    int b;
    scanf("%d", &a);
    scanf("%d", &b);

    int abs = a >= 0 ? a : -a;
    int max = a >= b ? a : b;

    printf("%d\n", abs);
    printf("%d\n", max);

    return 0;
}
