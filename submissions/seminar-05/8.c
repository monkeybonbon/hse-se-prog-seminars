#include <stdio.h>

int main(void){

    char a[8][8]; int ind1; int ind2;

    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            scanf(" %c", &a[i][j]);
            if (a[i][j] == 'R'){
                ind1 = i;
                ind2 = j;
            }
        }
    }

    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if (i == ind1 ^ j == ind2){
                a[i][j] = '*';
            }
        }
    }

    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){    
            printf("%c", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}