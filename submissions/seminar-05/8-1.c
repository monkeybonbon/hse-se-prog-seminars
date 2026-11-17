#include "stdio.h"

int main()
{
    int n = 8; 

    int x = -1, y = -1;
    char ans[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            char c; 
            scanf("%c", &c); 

            if (c == 'R') {
                x = i, y = j; 
            }
            if (j != n)
                ans[i][j] = '.';
        }
    }



    for (int i = 0; i < n; i++) {
        ans[i][y] = '*'; 
        ans[x][i] = '*'; 
    }

    ans[x][y] = 'R'; 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c", ans[i][j]); 
        }
        printf("\n"); 
    }
}
