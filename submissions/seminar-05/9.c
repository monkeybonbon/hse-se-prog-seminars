#include <stdio.h>

int main(void) {
    int N, M;
    if (scanf("%d %d", &N, &M) != 2 || N <= 0 || M <= 0) {
        return 1;
    }

    int a[N][M];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int total = N * M;
    for (int i = 0; i < total - 1; i++) { // пузырьком сорт
        for (int j = 0; j < total - 1 - i; j++) {
            int r1 = j / M, c1 = j % M;
            int r2 = (j + 1) / M, c2 = (j + 1) % M;

            if (a[r1][c1] < a[r2][c2]) {
                int tmp = a[r1][c1];
                a[r1][c1] = a[r2][c2];
                a[r2][c2] = tmp;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j > 0) {
                printf(" ");
            }
            printf("%d", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}