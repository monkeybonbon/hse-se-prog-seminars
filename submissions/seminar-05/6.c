#include <stdio.h>

int main(void){
    int m = 3, n = 4;
    int a[m][n];

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &a[i][j]);
        }
    }

    int sum_str, sum_stolb;

    printf("Сумма строк: ");

    for (int i = 0; i < m; i++){
        sum_str = 0;
        for (int j = 0; j < n; j++){
            sum_str += a[i][j];
        }
        printf("%d ", sum_str);
    }

    printf("\n");

    printf("Сумма столбцов: ");

    for (int j = 0; j < n; j++){
        sum_stolb = 0;
        for (int i = 0; i < m; i++){
            sum_stolb += a[i][j];
        }
        printf("%d ", sum_stolb);
    }

    printf("\n");


    return 0;
}