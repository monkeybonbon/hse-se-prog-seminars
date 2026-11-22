#include <stdio.h>

int main(void) {
    char board[8][8];
    int row = -1;
    int column = -1;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            scanf(" %c", &board[i][j]);
            if (board[i][j] == 'R') {
                row = i;
                column = j;
            }
        }
    }

    if (row == -1) {
        return 0;
    }

    for (int i = 0; i < 8; i++) {
        board[row][i] = '*';
        board[i][column] = '*';
    }
    board[row][column] = 'R';

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}