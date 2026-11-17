#include <stdio.h>
int main(void){
    int m[3][4];

    for (int i = 0; i<3; i++){
        for (int j = 0; j<4 ;j++){
            scanf("%d", &m[i][j]);
        }
    }

    int sumstr[] = {0,0,0};
    int sumcolumn[] = {0,0,0,0};

    for (int i=0; i<3; i++){
        for (int j = 0; j<4;j++){
            sumstr[i]+=m[i][j];
            sumcolumn[j]+=m[i][j];
        }
    }
    printf("Сумма строк: %d, %d, %d\n", sumstr[0], sumstr[1], sumstr[2]);
    printf("Сумма столбцов: %d, %d, %d, %d\n", sumcolumn[0], sumcolumn[1], sumcolumn[2], sumcolumn[3]);


    return 0;
} 