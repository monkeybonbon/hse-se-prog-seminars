#include <stdio.h>

unsigned digit_sum(unsigned n){
    if (n/10 !=0){
        return n % 10 + digit_sum(n/10);
    }
    return n;
}

int main(void){
    int a = digit_sum(0);
    printf("%d\n", a);
    return 0;
}