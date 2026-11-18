#include <stdio.h>

int main() {
    int b = 1, s = 0;

    while (b != 0) {
        scanf("%d", &b);
        s += b;
    }

    printf("%d\n", s);
    return 0;
}
