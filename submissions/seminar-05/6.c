#include <stdio.h>

int main(void) {
    int m[3][4];
    int sr[3] = {0};
    int sc[4] = {0};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            sr[i] += m[i][j];
            sc[j] += m[i][j];
        }
    }

    printf("Суммы строк: %d %d %d\n", sr[0], sr[1], sr[2]);
    printf("Суммы столбцов: %d %d %d %d\n", sc[0], sc[1], sc[2], sc[3]);
    return 0;
}