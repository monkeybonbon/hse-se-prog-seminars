#include <stdio.h>


int main(void) {

    char a[8][8];

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            scanf(" %c", &a[i][j]);
        }
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (a[i][j] == 'R') {
                for (int k = 0; k < 8; k++) {
                    if (k != j) {
                        a[i][k] = '*';
                    }
                    if (k != i) {
                        a[k][j] = '*';
                    }
                }
            }
        }
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}