#include <stdio.h>

int main(void){
    double x1,x2,y1,y2;
    scanf("%lf %lf %lf %lf", &x1,&x2,&y1,&y2);
    double a = x2 - x1;
    double b = y2 - y1;
    double s = a*b;
    double p = 2*a + 2*b;
    double q = a*a + b*b;
    printf("%.3f %.3f %.3f", p, s, q);
    return 0;
}
