#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Введите размер матрицы: ");
    scanf("%d", &n);

    int* a = malloc(n * n * sizeof(int));

    if (a == NULL) {
        printf("Ошибка выделения памяти\n");
        return 1;
    }

    printf("Введите элементы матрицы:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i * n + j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int temp = a[i * n + j];
            a[i * n + j] = a[j * n + i];
            a[j * n + i] = temp;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            int temp = a[i * n + j];
            a[i * n + j] = a[i * n + (n - 1 - j)];
            a[i * n + (n - 1 - j)] = temp;
        }
    }

    printf("Матрица после поворота на 90 градусов:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i * n + j]);
        }
        printf("\n");
    }

    free(a);

    return 0;
}