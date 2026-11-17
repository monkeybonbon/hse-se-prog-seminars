#include <stdio.h>

int main(void) {
    int a[3][4];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (scanf("%d", &a[i][j]) != 1) {
                return 1;
            }
        }
    }

    printf("Суммы строк:");

    for (int i = 0; i < 3; i++) {
        long s = 0;

        for (int j = 0; j < 4; j++) {
            s += a[i][j];
        }

        printf(" %ld", s);
    }

    printf("\nСуммы столбцов:");

    for (int j = 0; j < 4; j++) {
        long s = 0;

        for (int i = 0; i < 3; i++) {
            s += a[i][j];
        }

        printf(" %ld", s);
    }

    printf("\n");

    return 0;
}