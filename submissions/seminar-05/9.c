#include "stdio.h"

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {

            for (int i1 = i; i1 < n; ++i1) {
                for (int j1 = 0; j1 < m; ++j1) {
                    if ((i1 > i || j1 > j) && a[i1][j1] > a[i][j]) {
                        int t = a[i][j];
                        a[i][j] = a[i1][j1];
                        a[i1][j1] = t;
                    }
                }
            }

        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}