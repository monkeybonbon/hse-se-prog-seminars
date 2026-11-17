#include <stdio.h>

int main(void){
    int a, b;
    scanf("%d %d", &a, &b);
    int q = b-a+1;
    if(q%2 != 0){
        int s = b/2;
        int x = a*(s+1) + s + b*s;
        printf("%d", x);
    }
    else{
        int s = b/2;
        int x = a*s + b*s;
        printf("%d", x);
    }
    return 0;
}
