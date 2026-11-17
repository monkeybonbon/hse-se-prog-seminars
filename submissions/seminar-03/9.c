#include <stdio.h>

int main(void){
    int s;
    scanf("%d", &s);
    do{
        printf("%d", s%10);
        s = s/10;
    }while(s != 0);
    return 0;
}
