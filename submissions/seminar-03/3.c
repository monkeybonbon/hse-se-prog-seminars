#include <stdio.h>

int main(void) {
    int a;
    scanf("%d", &a);

    printf("%d\n", -5 <= a && a <= 19);
    printf("%d\n", a <= 8 || a > 12);

    return 0;
}
