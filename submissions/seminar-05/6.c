#include <stdio.h>

int main(void) {
    int a[3][4];

    int s_str = 0, s_stb = 0;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            scanf("%d", &a[i][j]);
        }
    }

    printf("Сумма строк: ");


    for (int i = 0; i < 3; i++){
        s_str = 0;
        for (int j = 0; j < 4; j++) {
            s_str += a[i][j];
        }
        printf("%d ", s_str);
    }

    printf("Сумма столбцов: ");

    for (int j = 0; j < 4; j++){
        s_stb=0;
        for (int i = 0; i < 3; i++) {
            s_stb += a[i][j];
        }
        printf("%d ", s_stb);
    }

}