#include <stdio.h>

double fast_pow(double x, unsigned n){
    if (n==0) {return 1.0;}
    if (n==1) {return x;}
    if (n>0 && n%2==0){
        double x_1 = fast_pow(x, n/2);
        return x_1*x_1;
    }
    double x_1 = fast_pow(x, (n-1)/2);
    return x*x_1*x_1;

}

int main(void){
    double x;
    unsigned n;
    scanf("%lf %u", &x, &n);
    printf("%lf", fast_pow(x,n));
    return 0;
}