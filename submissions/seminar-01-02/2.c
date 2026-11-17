#include <stdio.h>

int main(void){
    double x1,x2,x3,x4,x5,x6,x7,x8,x9,x10;
    scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", &x1,&x2,&x3,&x4,&x5,&x6,&x7,&x8,&x9,&x10);
    double a = (x1+x2+x3+x4+x5+x6+x7+x8+x9+x10)/10.0;
    double b = x1*x2*x3*x4*x5*x6*x7*x8*x9*x10;
    printf("%.3f %.3f\n", a, b);
    return 0;
}
