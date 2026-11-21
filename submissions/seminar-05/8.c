#include <stdio.h>

int main(void) {
    char a[8][8];
    int x = -1, y = -1;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            scanf(" %c", &a[i][j]);
        }
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
            if (a[i][j] != 'R' && (i == x || j == y)) {
                a[i][j] = '*';
            }
        }
    }

    for (int i = 0; i < 8; i++)  printf("%s\n", a[i]);
    return 0;
}
