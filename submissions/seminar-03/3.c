#include <stdio.h>

int main(void){
    int x = 0;
    scanf("%d", &x);
    printf("%d\t", x >= -5 && x <= 19);
    printf("%d\n", x <= 8 || x > 12);
    return 0;
}
