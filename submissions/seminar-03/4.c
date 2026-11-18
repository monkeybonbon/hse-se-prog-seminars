#include <stdio.h>

int main(void) {
    int a, b;

    scanf("%d", &a);
    printf("%d\n", a >= 0 ? a : -a);

    scanf("%d %d", &a, &b);
    printf("%d\n", a > b ? a : b);

    return 0;
}
