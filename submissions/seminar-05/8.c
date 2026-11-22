#include <stdio.h>

int main() {
    char b[8][8];
    int ri = 0, rj = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            scanf(" %c", &b[i][j]);
            if (b[i][j] == 'R') {
                ri = i;
                rj = j;
            }
        }
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i == ri || j == rj) && b[i][j] != 'R') {
                printf("*");
            } else {
                printf("%c", b[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}
