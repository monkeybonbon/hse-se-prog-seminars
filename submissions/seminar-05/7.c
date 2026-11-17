#include "stdio.h"

int main()
{
    int n, m; 
    scanf("%d %d", &n, &m); 

    int maxes = (n > m ? n : m); 

    int s[maxes][maxes], s_new[maxes][maxes];

    for (int i = 0; i < maxes; i++) {
        for (int j = 0; j < maxes; j++) {
            s[i][j] = 0; 
            s_new[i][j] = 0; 
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            s[i][j] = i * m + j + 1;  
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            s_new[i][j] = s[j][i]; 
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", s_new[i][j]); 
        }
        printf("\n"); 
    }
}   
