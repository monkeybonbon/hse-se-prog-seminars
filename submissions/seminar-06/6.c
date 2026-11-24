#include <stdio.h>

int max(int a, int b) {
    if (a >= b) return a;
    else return b;
}

int min(int a, int b) {
    if (a <= b) return a;
    else return b;
}

void normalize(int *a, int *b, int *c) {
    int temp_max = max(max(*a, *b), *c);
    int temp_min = min(min(*a, *b), *c);
    *a = temp_min;
    *b = (*a + *b + *c) - (temp_max + temp_min);
    *c = temp_max;
    printf("%d %d %d", *a, *b, *c);
}

int main(void) {
    int a = 5;
    int b = 10;
    int c = 7;
    normalize(&a, &b, &c);
    return 0;
}