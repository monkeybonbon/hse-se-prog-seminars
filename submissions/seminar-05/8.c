#include <stdio.h>

int main(void) {
    char b[8][8];
    int li, lj;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            scanf(" %c", &b[i][j]);
            if (b[i][j] == 'R') {
                li = i;
                lj = j;
            }
        }
    }

    printf("\n");
    for (int i = 0; i < 8; i++) {
        if (b[i][lj] != 'R') {
            b[i][lj] = '*';
        }
    }

    for (int j = 0; j < 8; j++) {
        if (b[li][j] != 'R') {
            b[li][j] = '*';
        }
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c", b[i][j]);
        }
        printf("\n");
    }

    return 0;
}