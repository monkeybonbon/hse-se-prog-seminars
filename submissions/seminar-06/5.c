#include <stdio.h>

unsigned digit_sum(unsigned n) {
    if (n <= 0)
        return 0;
    int a = digit_sum(n / 10) + n%10;
    return a;

}


int main(void) {
    printf("%u", digit_sum(123));
}