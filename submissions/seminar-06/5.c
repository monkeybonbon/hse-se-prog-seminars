#include<stdio.h>

unsigned digit_sum(unsigned n){
    unsigned sum = 0;
    while (n){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main(void){
    printf("%u\n", digit_sum(12345u));
    printf("%u\n", digit_sum(9007u));
    printf("%u\n", digit_sum(0u));

    return 0;
}

/*
digit_sum(12345) → 15
digit_sum(9007)  → 16
digit_sum(0)     → 0
*/