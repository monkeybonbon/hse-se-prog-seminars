#include <stdio.h>

int main(void) {
    char a[8][8];


    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            scanf(" %c", &a[i][j]);
        }
    }
    int n;
    int m;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (a[i][j] == 'R') {
                n = i;
                m = j;
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i == n || j == m) && a[i][j] != 'R') {
                a[i][j] = '*';
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c", a[i][j]);
        }
        printf("\n");
    }

}