#include <stdio.h>

int main(void) {
    char a[8][8];

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            scanf(" %c", &a[i][j]);
        }
    }

    int x, y;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (a[i][j] == 'R') {
                x = i;
                y = j;
            }
        }
    }
    for (int j = 0; j < 8; j++) {
        if (j != y) {
            a[x][j] = '*';
        }
    }
    for (int i = 0; i < 8; i++) {
        if (i != x) {
            a[i][y] = '*';
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}