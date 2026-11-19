#include <stdio.h>

int main(void) {
    int x;
    int sum = 0;

    while (1) {
        scanf("%d", &x);

        if (x == 0) {
            break;
        }

        sum += x;
    }

    printf("%d\n", sum);

    return 0;
}
