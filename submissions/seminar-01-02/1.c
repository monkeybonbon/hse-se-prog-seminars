#include <stdio.h>

const double PI = 3.1415;


int main(void){
    int x;
    if (scanf("%d", &x) != 1){
        return 1;
    };
    printf("%c", x%2 + '0');
    x/=2;
    printf("%c", x%2 + '0');
    x/=2;
    printf("%c", x%2 + '0');
    x/=2;
    printf("%c", x%2 + '0');
    x/=2;
    printf("%c", x%2 + '0');
    x/=2;
    printf("%c", x%2 + '0');
    x/=2;
    printf("%c", x%2 + '0');
    x/=2;
    printf("%c", x%2 + '0');
    x/=2;
    return 0;
}
