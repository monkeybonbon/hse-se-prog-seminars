#include "stdio.h"

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; 
    scanf("%d", &n);

    int s[n][n]; 

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &s[i][j]); 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int c = s[i][j]; 
            s[i][j] = s[j][i]; 
            s[j][i] = c; 
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            int c = s[i][j]; 
            s[i][j] = s[i][n - j - 1]; 
            s[i][n - j - 1] = c;  
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", s[i][j]); 
        }
        printf("\n"); 
    }
}

