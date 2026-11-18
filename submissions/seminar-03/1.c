#include <stdio.h>

long long mult (int a, int b) {
    return (long long) a * b;
}

// в том что a * b - int, а нужно ll

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%lld\n", mult(a, b));
    return 0;
}
