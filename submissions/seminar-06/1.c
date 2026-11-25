#include <stdio.h>

void update(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
}

int main(void) {
    int x = 3;
    int y = 7;
    update(&x, &y); // 10 3
    printf("%d %d\n", x, y);

    x = 3;
    update(&x, &x); // 0
    printf("%d\n", x);

    return 0;
}
