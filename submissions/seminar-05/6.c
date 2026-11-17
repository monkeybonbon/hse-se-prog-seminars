#include <stdio.h>

int main(void) {
    int a[3][4];
    int str[3];
    int stl[4];
    int c = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Суммы строк: ");
    for (int i = 0; i < 3; i++) {
        c = 0;
        for (int j = 0; j < 4; j++) {
            c += a[i][j];
        }
        printf("%d ", c);
    }
    printf("\n");
    printf("Суммы столбцов: ");
    for (int i = 0; i < 4; i++) {
        c = 0;
        for (int j = 0; j < 3; j++) {
            c += a[j][i];
        }
        printf("%d ", c);
    }
    printf("\n");
    return 0;
}