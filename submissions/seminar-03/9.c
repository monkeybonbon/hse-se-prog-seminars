#include <stdio.h>
int main(void) {
    unsigned int n;

    scanf("%u", &n);

    do{
        printf("%u", n%10);
        n/=10;
    } while (n>0);
    printf("\n");
    return 0;
}