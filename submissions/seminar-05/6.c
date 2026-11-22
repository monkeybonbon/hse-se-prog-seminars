#include <stdio.h>

int main(void){
    int a[3][4];
    long long rows[3] = {0};
    long long cols[4] = {0};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (scanf("%d", &a[i][j]) != 1) {
                return 1;
            }
            rows[i] += a[i][j];
            cols[j] += a[i][j];
        }
    }

    printf("Суммы строк:");
    for (int i = 0; i < 3; i++) {
        printf(" %lld", rows[i]);
    }
    printf("\n");

    printf("Суммы столбцов:");
    for (int j = 0; j < 4; j++) {
        printf(" %lld", cols[j]);
    }
    printf("\n");

    return 0;
}