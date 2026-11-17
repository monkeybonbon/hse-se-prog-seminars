#include <stdio.h>

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n][m];
    int v = 0, d = n - 1, l = 0, r = m - 1, c = 1;
    while (c < n*m + 1) {
        for (int i = l; i <= r; i++) {
            a[v][i] = c++;
        }
        if (c > n * m) { break;}
        v++;
        for (int i = v; i <= d; i++) {
            a[i][r] = c++;
        }
        if (c > n * m) { break;}
        r--;
        for (int i = r; i >= l; i--) {
            a[d][i] = c++;
        }
        if (c > n * m) { break;}
        d--;
        for (int i = d; i >= v; i--) {
            a[i][l] = c++;
        }
        if (c > n * m) { break;}
        l++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}