#include <stdio.h>
void update(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
}

int main(void) {
    int x = 3;
    update(&x, &x);
    // 10 3 в первом случае
    printf("%d", x);
    // 0 в втором случае
    return 0;
}