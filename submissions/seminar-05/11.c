#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;

    printf("Введите размеры матрицы (N M): ");
    scanf("%d %d", &n, &m);

    int* a = malloc(n * m * sizeof(int));

    if (a == NULL) {
        printf("Ошибка выделения памяти\n");
        return 1;
    }

    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;
    int num = 1;

    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++) {
            a[top * m + j] = num++;
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            a[i * m + right] = num++;
        }
        right--;

        for (int j = right; j >= left; j--) {
            a[bottom * m + j] = num++;
        }
        bottom--;

        for (int i = bottom; i >= top; i--) {
            a[i * m + left] = num++;
        }
        left++;
    }

    printf("\nМатрица, заполненная по спирали:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", a[i * m + j]);
        }
        printf("\n");
    }

    free(a);

    return 0;
}