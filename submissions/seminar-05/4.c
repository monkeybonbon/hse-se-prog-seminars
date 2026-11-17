#include <stdio.h>
int main(){
int b[4][5]; 
int *p = &b[2][1], *q = &b[3][4];
printf("%td\n",q - (int *)b); // 19
printf("%td\n",p - (int *)b); // 11
printf("%td\n",p - q); // -8
    }