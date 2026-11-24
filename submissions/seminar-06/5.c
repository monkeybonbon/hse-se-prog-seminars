#include <stdio.h>

unsigned digit_sum(unsigned n){
    if (n/10==0){
        return n;
    }
    return digit_sum(n/10)+n%10;
}

int main(void){
    unsigned x;
    scanf("%u", &x);
    printf("%u\n", digit_sum(x));

    return 0;
}