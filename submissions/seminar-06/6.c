#include <stdio.h>

void normalize(int *a, int *b, int *c){
    if (*a>*c){
        int temp = *c;
        *c = *a;
        *a = temp;
    }
    if (*a>*b){
        int temp = *b;
        *b = *a;
        *a = temp;
    }
    if (*b>*c){
        int temp = *c;
        *c = *b;
        *b = temp;
    }
}

int main(void){
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    normalize(&a,&b,&c);
    printf("%d %d %d \n", a,b,c);
    return 0;
}