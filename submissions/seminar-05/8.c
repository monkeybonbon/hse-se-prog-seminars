#include <stdio.h>

int main(void)
{
    char board[8][8];
    int row = 0, col = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            scanf(" %c", &board[i][j]);
            if (board[i][j] == 'R')
            {
                row = i;
                col = j;
            }
        }
    }

    for (int i = 0; i < 8; i++)
    {
        board[row][i] = '*';
        board[i][col] = '*';
    }
    board[row][col] = 'R';

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}
