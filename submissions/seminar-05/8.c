#include <stdio.h>

int main(void) {
    char a[8][9];
    int x = 0, y = 0;

    for (int i = 0; i < 8; i++) {
        scanf("%8s", a[i]);
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (a[i][j] == 'R') {
                x = i;
                y = j;
            }
        }
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (i == x || j == y) {
                if (a[i][j] != 'R') {
                    a[i][j] = '*';
                }
            }
        }
    }

    for (int i = 0; i < 8; i++) {
        printf("%s\n", a[i]);
    }

    return 0;
}