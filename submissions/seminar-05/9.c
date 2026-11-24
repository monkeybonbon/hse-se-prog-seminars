
#include <stdio.h>

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);

    int a[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < n * m; i++) {
        for (int j = i + 1; j < n * m; j++) {
            if (a[i / m][i % m] < a[j / m][j % m]) {
                int t = a[i / m][i % m];
                a[i / m][i % m] = a[j / m][j % m];
                a[j / m][j % m] = t;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
