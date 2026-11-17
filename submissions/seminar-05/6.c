#include <stdio.h>

int main(void) {
    int a[3][4];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Суммы строк: ");
    for (int i = 0; i < 3; i++) {
        int sum = 0;
        for (int j = 0; j < 4; j++) {
            sum += a[i][j];
        }
        printf("%d ", sum);
    }

    printf("\nСуммы столбцов: ");
    for (int i = 0; i < 4; i++) {
        int sum = 0;
        for (int j = 0; j < 3; j++) {
            sum += a[j][i];
        }
        printf("%d ", sum);
    }

}