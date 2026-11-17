#include "stdio.h"

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            a[i][j] = 0;
        }
    }

    int i[] = {0, 1, 0, -1};
    int j[] = {1, 0, -1, 0};
    int cur = 0, inow = 0, jnow = 0;

    for (int val = 1; val <= n * m; ++val) {
        a[inow][jnow] = val;
        if (inow + i[cur] < 0 || inow + i[cur] >= n ||
            jnow + j[cur] < 0 || jnow + j[cur] >= m) {
            cur = (cur + 1) % 4;
        } else if (a[inow + i[cur]][jnow + j[cur]]) {
            cur = (cur + 1) % 4;
        }

        inow += i[cur];
        jnow += j[cur];
    }

    for (int k = 0; k < n; ++k) {
        for (int l = 0; l < m; ++l) {
            printf("%d ", a[k][l]);
        }
        printf("\n");
    }

}