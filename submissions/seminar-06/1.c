#include <stdio.h>

void update(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
}

int main(void) {
    int x = 3, y = 7;
    update(&x, &y);
    printf("Case A: x = %d, y = %d\n", x, y);

    x = 3;
    update(&x, &x);
    printf("Case B: x = %d\n", x);

    return 0;
}
