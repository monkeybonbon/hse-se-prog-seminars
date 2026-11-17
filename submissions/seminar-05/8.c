#include <stdio.h>

int main(void) {
    char a[8][8];
    int first, second;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++){
            scanf("%c", &a[i][j]);
            if (a[i][j] == "R") {
                first = i;
                second = j;
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        a[first][i] = '*';
    }
    for (int j = 0; j < 8; j++) {
        a[j][second] = '*';
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%d", a[i][j]);
        }
    }

}