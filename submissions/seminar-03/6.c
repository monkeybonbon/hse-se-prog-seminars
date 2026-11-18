#include <stdio.h>
int main(void){
    int x;
    long long sum = 0;

    scanf("%d", &x);

    while (x != 0){
        sum += x;
        scanf("%d", &x);
        
    }
    printf("%lld\n", sum);

    return 0;
}