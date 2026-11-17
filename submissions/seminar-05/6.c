#include <stdio.h>
int main () {
    int a[3][4];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    int ans1[3] = {0, 0, 0};
    int ans2[4] = {0, 0, 0, 0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            ans1[i] += a[i][j];
        }
    }
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < 3; i++) {
            ans2[j] += a[i][j];
        }
    }
    printf("Сумма строк: ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", ans1[i]);
    }
    printf("\n");
    printf("Сумма столбцов: ");
    for (int j = 0; j < 4; j++) {
        printf("%d ", ans2[j]);
    }
    printf("\n");
    return 0;
}