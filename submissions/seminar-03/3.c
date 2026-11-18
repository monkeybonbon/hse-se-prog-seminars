#include <stdio.h>

int main(void) {
    int x;
    scanf("%d", &x);

    printf("%d\n", x >= -5 && x <= 19);
    printf("%d\n", x <= 8 || x > 12);

    return 0;
}
