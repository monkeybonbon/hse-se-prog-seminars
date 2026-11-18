#include <stdio.h>

int main(void) {
    int n, div = 1;
    scanf("%d", &n);

    while (n / div >= 10) {
        div *= 10;
    }

    while (div > 0) {
        printf("%d", n / div);
        n %= div;
        div /= 10;

        if (div > 0)
            printf(" ");
    }

    printf("\n");
    return 0;
}