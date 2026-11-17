#include <stdio.h>

int main()
{
    int n;
    int m;
    scanf_s("%d", &n);
    scanf_s("%d", &m);
    int matrix[100][100];
    int trans[100][100];
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            scanf_s("%d", &matrix[i][j]);
        }
    }
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++)
        {
            trans[j][i] = matrix[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", trans[i][j]);
        }
        printf("\n");
    }
    return 0;
}