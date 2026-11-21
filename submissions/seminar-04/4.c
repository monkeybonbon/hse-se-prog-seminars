#include <stdio.h>

int main(void) {
    int n, a[100], x;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &x);
    a[n] = x;
    n++;

    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");
    return 0;
}
