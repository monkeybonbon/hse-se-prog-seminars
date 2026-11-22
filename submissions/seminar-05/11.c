#include <stdio.h>

int main(void) {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2 || n <= 0 || m <= 0) {
        return 0;
    }

    int a[n][m];
    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = m - 1;
    int number = 0;

    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++) {
            a[top][j] = ++number;
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            a[i][right] = ++number;
        }
        right--;

        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                a[bottom][j] = ++number;
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                a[i][left] = ++number;
            }
            left++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j > 0) {
                printf(" ");
            }
            printf("%d", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}