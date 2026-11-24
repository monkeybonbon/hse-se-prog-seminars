#include <stdio.h>
double fast_pow(double x, unsigned n) {
    if (n == 0) {
        return 1;
    } else if (n > 0 && n % 2 == 0) {
        double res = fast_pow(x, n / 2);
        return res * res;
    } else {
        double res = fast_pow(x, n / 2);
        return x * res * res;
    }
}
int main(void) {
    double x;
    unsigned n;
    scanf("%lf %u", &x, &n);
    double result = fast_pow(x, n);
    printf("%lf", result);
    return 0;
}