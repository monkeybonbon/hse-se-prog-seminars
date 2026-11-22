#include <stdio.h>

int main(void) {
    int n;
    int a[100]; 
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int x;
    scanf("%d", &x);
    a[n]=x;


    for (int j = 0; j <= n; j++) {
        printf("%d ", a[j]);
    }

    return 0;
}