#include <stdio.h>
void normalize(int *a, int *b, int *c)
{
    int temp;

    if (*a > *b) {
        temp = *a;
        *a = *b;
        *b = temp;
    }

    if (*b > *c) {
        temp = *b;
        *b = *c;
        *c = temp;
    }

    if (*a > *b) {
        temp = *a;
        *a = *b;
        *b = temp;
    }
}

int main(void) {
    int a = 10, b = 20, c = 1;
    printf("%d %d %d\n", a, b, c);
    normalize(&a, &b, &c);
    printf("%d %d %d\n", a, b, c);
}