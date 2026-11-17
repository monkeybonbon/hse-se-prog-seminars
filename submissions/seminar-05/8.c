#include <stdio.h>

int main(void) {

    int n = 8, m = 8;
    char arr[8][8];
     int row = -1, col = -1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf(" %c", &arr[i][j]);
            if (arr[i][j] == 'R') {
                row = i;
                col = j;
            }
        }
    }


    for (int k = 0; k < 8; k++) {
        if (arr[row][k] == '.') {
            arr[row][k] = '*';
        }
        if (arr[k][col] == '.') {
            arr[k][col] = '*';
        }
    }


    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}