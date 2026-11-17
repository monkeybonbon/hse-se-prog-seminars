#include <stdio.h>

int main(void){
    int x = 0;
    int s = 0;
    do{
        scanf("%d", &x);
        s += x;
    }while(x != 0);
    printf("%d", s);
    return 0;
}   
