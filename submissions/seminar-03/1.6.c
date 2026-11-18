#include <stdio.h>

int main(void) {
    int a, sum = 0;

    while (scanf("%d", &a) == 1 && a != 0) {
        sum += a;
    }

    printf("%d\n", sum);
    return 0;
}