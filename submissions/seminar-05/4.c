#include <stdio.h>
int main(void){
    int b[4][5]; 
    int *p = &b[2][1];
    int *q = &b[3][4];
    printf("%d\n", p - q);
    return 0;
} 
/*
a) 19
б) 11
в) -8
*/