#include <stdio.h>

unsigned digit_sum(unsigned n) {
    unsigned k;
    k += n % 10;
    if (n <= 0) return k;
    n /= 10;
    return digit_sum(n);
}

int main (void) {
    printf("%d", digit_sum(123456));
    return 0;
}