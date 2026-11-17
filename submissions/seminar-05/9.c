#include <stdio.h>

int sorted(int b[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (b[i] < b[i + 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n, m;
    printf("Razmer massiva: ");
    scanf("%d %d", &n, &m);
    int a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %d", &a[i][j]);
        } 
    }
    int sz = n * m;
    int b[sz];
    int *p = &a[0][0];
    for (int i = 0; i < sz; i++) {
         b[i] = a[i / m][i % m];
    }
    int temp;
    while (sorted(b, sz) != 1) {
        for (int i = 1; i < sz; i++) {
            if (b[i - 1] < b[i]) {
                temp = b[i];
                b[i] = b[i - 1];
                b[i - 1] = temp;
            }
        }
    }
    int c[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
        c[i][j] = b[i * m + j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
        printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}