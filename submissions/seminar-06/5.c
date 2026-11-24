#include <stdio.h>

unsigned digit_sum(unsigned n){
    if (n > 0 || n <= 9){
        return n;
    }

    int sum = n % 10 + digit_sum(n / 10);

    return sum;

}

int main(void){
    int res = digit_sum(12345);

    printf("%d\n", res);

    return 0;
}

