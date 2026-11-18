#include <stdio.h>

int main(void) {
    int n, d = 1;
    scanf("%d", &n);

    while (n / d >= 10) {
        d = d * 10;
    }

    while (d > 0) {
        printf("%d ", n / d);
        n = n % d;
        d = d / 10;
    }
    return 0;
}
