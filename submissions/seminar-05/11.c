#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n][m];
    int t = 0, b = n - 1, l = 0, r = m - 1, k = 1;

    while (t <= b && l <= r) {
        for (int j = l; j <= r; j++) {
            a[t][j] = k++;
        }
        t++;
        for (int i = t; i <= b; i++) {
            a[i][r] = k++;
        }
        r--;
        if (t <= b) {
            for (int j = r; j >= l; j--) {
                a[b][j] = k++;
            }
            b--;
        }
        if (l <= r) {
            for (int i = b; i >= t; i--) {
                a[i][l] = k++;
            }
            l++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%2d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
