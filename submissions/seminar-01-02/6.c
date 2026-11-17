#include <stdio.h>

int main(void){
    char a1,a2,a3,a4,a5,a6,a7,a8,a9,a10;
    int x;
    scanf("%c %c %c %c %c %c %c %c %c %c %d/n", &a1, &a2, &a3, &a4, &a5, &a6, &a7, &a8, &a9, &a10, &x);
    x = x%26;
    printf("%c %c %c %c %c %c %c %c %c %c", a1+x,a2+x,a3+x,a4+x,a5+x,a6+x,a7+x,a8+x,a9+x,a10+x);
    return 0;
}
