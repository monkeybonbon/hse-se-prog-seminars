#include <stdio.h>

int main(void) {
    int n;
    int a[100]; 
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int j = n-1; j >= 0; j--) {
        printf("%d ", a[j]);
    }

    return 0;
}