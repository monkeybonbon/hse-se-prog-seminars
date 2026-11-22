#include <stdio.h>

int main(void) {
    int n;
    int a[100]; 
    long long int sum = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int j = 0; j < n; j++) {
        sum = sum + a[j];
    }

    printf("%lld\n", sum);
    

    return 0;
}