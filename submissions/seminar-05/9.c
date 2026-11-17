#include <stdio.h>

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int a[10000];
    int total = n * m;

    for (int i = 0; i < total; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - 1 - i; j++) {
            if (a[j] < a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", a[i * m + j]);
        }
        printf("\n");
    }

    return 0;
}