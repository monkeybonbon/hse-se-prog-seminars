#include <stdio.h>

void update(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
}

int main(void) {
    int x = 3;
    update(&x, &x);
    printf("%d\n", x);
}

//случай а x = 10 y = 3

//случай б x = 0 