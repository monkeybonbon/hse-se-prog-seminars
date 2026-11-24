#include <stdio.h>

unsigned digit_sum(unsigned n) {
    unsigned count = 0;
    while (n > 0) {
        count += n % 10;
        n = n / 10;
    }
    return count;
}