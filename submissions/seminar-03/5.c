#include <stdio.h>

int main(void){
    int n, x;
    long long sum = 0;

    scanf ("%d", &n);
    
    for (int i = 0; i<n; i++){
        scanf("%d",&x);
        sum+=x;

    }
    printf("%lld\n", sum);
    return 0;
}