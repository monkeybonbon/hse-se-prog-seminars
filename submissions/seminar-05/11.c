#include <stdio.h>

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = 0;

    int x = 0, y = -1, num = 1;
    while (num <= n * m) {
        while (y + 1 < m && a[x][y + 1] == 0) {
            y++;
            a[x][y] = num++;
        }
        while (x + 1 < n && a[x + 1][y] == 0) {
            x++;
            a[x][y] = num++;
        }
        while (y - 1 >= 0 && a[x][y - 1] == 0) {
            y--;
            a[x][y] = num++;
        }
        while (x - 1 >= 0 && a[x - 1][y] == 0) {
            x--;
            a[x][y] = num++;
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