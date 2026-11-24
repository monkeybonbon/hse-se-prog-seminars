#include <stdio.h>

unsigned digit_sum(unsigned n) {
    unsigned s = 0;
    while (n > 0){ 
        s += n % 10;
        n /= 10;
    }
    return s;
}

int main(void) {
    printf("%u", digit_sum(12345));
    
}