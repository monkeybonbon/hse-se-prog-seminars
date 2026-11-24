#include <stdio.h>

double fast_pow(double x, unsigned n){
    if (n == 0){
        return 1;
    }

    double pol = fast_pow(x, n/2);

    if (n % 2 == 0){
        return pol * pol;
    }else{
        return x * pol * pol;
    }
}