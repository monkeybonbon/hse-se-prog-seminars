#include <stdio.h>

double fast_pow(double x, unsigned n) {
    if (n == 0)
        return 1.0;

    double h = fast_pow(x, n / 2);   
    if (n % 2 == 0)
        return h * h;
    return x * h * h;
}

int main(void) {
    printf("%g\n", fast_pow(2.0, 10));  
    printf("%g\n", fast_pow(3.0, 5));   
    printf("%g\n", fast_pow(0.5, 3));   
    printf("%g\n", fast_pow(7.0, 0));   
    printf("%g\n", fast_pow(-2.0, 3)); 
    return 0;
}