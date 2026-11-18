#include <stdio.h>
/*
int main(void) {
    int x;
    scanf("%d", &x);
    int res = (x >= 0) ? x : -x;
    printf( "%d\n", res);
    return 0;
}  
    */

int main(void) {
    int a;
    int b;
    scanf("%d %d", &a, &b);
    printf("%d\n", (a > b) ? a : b);
    return 0;
}