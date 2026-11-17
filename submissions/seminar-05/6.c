#include "stdio.h"

int main(void) {
    int a[3][4];
    int sumr[3];
    int sumc[4];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0, sum = 0; j < 4; ++j) {
            scanf("%d", &a[i][j]);
            sum += a[i][j];
            sumr[i] = sum;
        }
    }

    for (int j = 0; j < 4; ++j) {
        for (int i = 0, sum = 0; i < 3; ++i) {
            sum += a[i][j];
            sumc[j] = sum;
        }
    }

    printf("Суммы строк: %d %d %d\n", sumr[0], sumr[1], sumr[2]);
    printf("Суммы столбцов: %d %d %d %d\n", sumc[0], sumc[1], sumc[2], sumc[3]);
}