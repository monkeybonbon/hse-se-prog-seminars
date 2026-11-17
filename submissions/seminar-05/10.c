#include "stdio.h"

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m; 

    scanf("%d %d", &n, &m); 

    int s[n + 2][m + 2]; 

    for (int i = 0; i < n + 2; i++) s[i][0] = s[i][m + 1] = -1; 
    for (int j = 0; j < m + 2; j++) s[0][j] = s[n + 1][j] = -1;  
    
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++)
            s[i][j] = 0; 

    int x = 1, y = 1, cnt = 1; 

    while (!s[x][y]) {
        while (!s[x][y]) s[x][y++] = cnt++;
        y--, x++; 

        while (!s[x][y]) s[x++][y] = cnt++;
        x--, y--;

        while (!s[x][y]) s[x][y--] = cnt++;
        y++, x--;

        while (!s[x][y]) s[x--][y] = cnt++; 
        x++, y++;

    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) 
            printf("%d ", s[i][j]); 
        printf("\n"); 
    }
}

