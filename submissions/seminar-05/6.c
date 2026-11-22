#include <stdio.h>

int main(void){
    int a[3][4];
    for(int i=0;i<3;i++){
        for (int j=0;j<4;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("Суммы строк:");
    for (int i = 0; i < 3; i++) {
        long sum = 0;
        for (int j = 0; j < 4; j++) {
            sum += a[i][j];
        }
        printf(" %ld", sum);
    }
    printf("\n");
    printf("Суммы столбцов:");
    for (int j = 0; j < 4; j++) {
        long sum = 0;
        for (int i = 0; i < 3; i++) {
            sum += a[i][j];
        }
        printf(" %ld", sum);

    return 0;
}