#include <stdio.h>

int main(void) {
    int m[3][4];
    int cs1 = 0, cs2 = 0, cs3 = 0;
    int c1 = 0, c2 = 0, c3 = 0, c4 = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == 0) cs1 += m[i][j];
            else if (i == 1) cs2 += m[i][j];
            else cs3 += m[i][j];

            if (j == 0) c1 += m[i][j];
            else if (j == 1) c2 += m[i][j];
            else if (j == 2) c3 += m[i][j];
            else c4 += m[i][j];
        }
    }

    printf("Суммы строк: %d %d %d\n", cs1, cs2, cs3);
    printf("Суммы столбцов: %d %d %d %d\n", c1, c2, c3, c4);

    return 0;
}
