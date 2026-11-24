#include <stdio.h>

void normalize(int *a, int *b, int *c){
    int t = 0;
    if (*a > *b){
        t = *a;
        *a = *b;
        *b = t;
    }
    if (*b > *c) {
        t = *b;
        *b = *c;
        *c = t;
    }
    if (*a > *b){
        t = *a;
        *a = *b;
        *b = t;
    }
}

int main(void) {
    int x = 9, y = 2, z = 5;
    normalize(&x, &y, &z);
    printf("x = %d, y = %d, z = %d\n", x, y, z);
}