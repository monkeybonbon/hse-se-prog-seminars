#include <stdio.h>

int main(void){
    double r;
    scanf("%lf", &r);
    double s = 3.14 * r * r;
    double l = 2 * 3.14 * r;
    printf("%.3f %.3f", s, l);
    return 0;
}
