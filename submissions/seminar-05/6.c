#include <stdio.h>

int main(void) {
    int a[3][4];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Суммы строк:");
    for (int i = 0; i < 3; i++) {
        int s = 0;
        for (int j = 0; j < 4; j++) {
            s += a[i][j];
        }
        printf(" %d", s);
    }
    printf("\n");

    printf("Суммы столбцов:");
    for (int j = 0; j < 4; j++) {
        int s = 0;
        for (int i = 0; i < 3; i++) {
            s += a[i][j];
        }
        printf(" %d", s);
    }
    printf("\n");

    return 0;
}
