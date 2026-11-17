#include <stdio.h>

int main(void){

    int a[100][100];
    int x;
    int sum = 0;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 4; j++){
            scanf("%d", &x);
            a[i][j] = x;
        }
    }
    printf("Суммы строк: ");
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 4; j++){
            sum += a[i][j];
        }
        printf("%d ", sum);
        sum = 0;
    }
    printf("\n");

    printf("Суммы столбцов: ");
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 3; j++){
            sum += a[j][i];
        }
        printf("%d ", sum);
        sum = 0;
    }
}