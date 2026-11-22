#include <stdio.h>

int main(void) {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2 || n <= 0 || m <= 0) {
        return 0;
    }

    int a[n][m];
    size_t count = (size_t)n * m;
    int numbers[count];
    size_t k = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
            numbers[k] = a[i][j];
            k++;
        }
    }

    for (size_t i = 0; i + 1 < count; i++) {
        size_t max = i;
        for (size_t j = i + 1; j < count; j++) {
            if (numbers[j] > numbers[max]) {
                max = j;
            }
        }

        int temp = numbers[i];
        numbers[i] = numbers[max];
        numbers[max] = temp;
    }

    k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = numbers[k];
            k++;

            if (j > 0) {
                printf(" ");
            }
            printf("%d", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}