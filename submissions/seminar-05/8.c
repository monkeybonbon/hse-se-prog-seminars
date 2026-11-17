#include <stdio.h>


int main(void){
    int a[8][8];
    char x;
    int row_ind = 0;
    int tab_ind = 0;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            scanf("%c", &x);
            a[i][j] = x;
            if (x == 'R'){
                row_ind = i;
                tab_ind = j;
            }
        }
    }
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if (row_ind == i && tab_ind == j){
                a[i][j] = 'R';
            }else if (row_ind == i){
                a[i][j] = '*';
            }else if (tab_ind == j){
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
