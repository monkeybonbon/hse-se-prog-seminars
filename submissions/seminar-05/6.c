#include <stdio.h>

int main()
{
    int m[3][4];
    int row_sums[3] = { 0 }; 
    int col_sums[4] = { 0 }; 

    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            scanf_s("%d", &m[i][j]);
        }
    }

    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            
            row_sums[i] += m[i][j];
            col_sums[j] += m[i][j];
        }
    }

    printf("sum row: ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", row_sums[i]);
    }
    printf("\n"); 
    printf("sum col: ");
    for (int j = 0; j < 4; j++) {
        printf("%d ", col_sums[j]);
    }
    printf("\n");

    return 0;
}