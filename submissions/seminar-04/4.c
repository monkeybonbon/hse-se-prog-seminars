#include <stdio.h>

int main(void) {
    int n, x;
    int a[100];
    scanf("%d", &n);
    scanf("%d", &x);
    a[n] = x;
    for ( int i = 0; i < n+1; i++){
        printf("%d ", a[i]);
    };    
    return 0;
}
