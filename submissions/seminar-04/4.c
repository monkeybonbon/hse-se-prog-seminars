#include <stdio.h>

int main(void){
    int n, a[100], x;
    if (scanf("%d", &n) != 1 || n < 0 || n >= 100) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            return 1;
        }
    }
    if (scanf("%d", &x) != 1) {
        return 1;
    }

    a[n] = x;
    n++;
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");
     return 0;
}