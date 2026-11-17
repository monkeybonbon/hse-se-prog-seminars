#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;

    printf("Введите размеры матрицы (n m): ");
    scanf("%d %d", &n, &m);

    int* a = malloc(n * m * sizeof(int));
    int* b = malloc(m * n * sizeof(int));

    if (a == NULL || b == NULL) {
        printf("Ошибка выделения памяти\n");
        free(a);
        free(b);
        return 1;
    }

    printf("Введите элементы матрицы:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i * m + j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            b[j * n + i] = a[i * m + j];
        }
    }

    printf("Транспонированная матрица:\n");

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", b[i * n + j]);
        }
        printf("\n");
    }

    free(a);
    free(b);

    return 0;
}