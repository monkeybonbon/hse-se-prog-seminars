#include <stdio.h>

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n*m];
    for (int i = 0; i < n*m; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n*m; i++) {
        for (int j = 0; j < n*m; j++) {
            if (a[i] > a[j]) {
                int q = a[i];
                a[i] = a[j];
                a[j] = q;
            }
        }
    }

    for (int i = 0; i < n*m; i++) {
        printf(" %d", a[i]);
        if ((i + 1)%m == 0) {
            printf("\n");
        }
    }

    return 0;
}