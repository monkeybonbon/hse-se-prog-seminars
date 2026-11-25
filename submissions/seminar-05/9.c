#include <stdio.h>

int main(void) {
    int n;
    int m;
    scanf("%d%d", &n, &m);
    int arr[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    // Comb sort

    int gap = n * m;
    double coef = 1.3;
    int flag = 0;

    while (!flag) {
        gap = (int)(gap / coef);
        if (gap <= 1) {
            gap = 1;
            flag = 1;
        }

        for (int i = 0; i < n * m - gap; i++) {
            int *a = arr[0] + i;
            int *b = arr[0] + i + gap;
            if (*a < *b) {
                int t = *a;
                *a = *b;
                *b = t;
                flag = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
