#include "stdio.h"

int main(void) {
    char c[8][9];
    int ri, rj;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 9; ++j) {
            scanf("%c", &c[i][j]);
            if (c[i][j] == 'R') {
                ri = i, rj = j;
            }
        }
    }
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (i == ri || j == rj) {
                c[i][j] = '*';
            }
            if (i == ri && j == rj) {
                c[i][j] = 'R';
            }
        }
    }
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 9; ++j) {
            printf("%c", c[i][j]);
        }
    }

}