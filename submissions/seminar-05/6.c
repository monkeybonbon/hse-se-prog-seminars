#include <stdio.h>

int main(void) {
    int a[3][4];
    for (int i = 0; i < 3; i++) {
        int si = 0;
        for (int j = 0; j < 4; j++) {
            scanf("%d", &a[i][j]);
            si += a[i][j];
        }
        printf("%d", si);
    }
    printf("Суммы строк: ");
    for (int i = 0; i < 3; i++) {
        int si = 0;
        for (int j = 0; j < 4; j++) {
            si += a[i][j];
        }
        printf("%d ", si);
    }
    printf("\nСуммы столбцов: ");
    for (int j = 0; j < 4; j++) {
        int si = 0;
        for (int i = 0; i < 3; i++) {
            si += a[i][j];
        }
        printf("%d ", si);
    }

    return 0;
}