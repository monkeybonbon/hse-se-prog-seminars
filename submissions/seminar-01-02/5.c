#include <stdio.h>

int main(void){
    double a,b,c;
    if (scanf("%lfx^2 + %lfx + %lf", &a, &b, &c) != 3){
        return 1;
    };
    double d = b*b - 4*a*c;
    printf("%.3f", d);
    return 0;
}
