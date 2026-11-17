#include <stdio.h>
int main(void){
    char d[8][8];
    int row, col = -1;

    for (int i = 0; i<8; i++){
        for (int j = 0; j<8 ;j++){
            scanf("%c", &d[i][j]);
        }
    }
    for (int i = 0; i<8; i++){
        for (int j = 0; j<8 ;j++){
            if (d[i][j]=='R'){
                row = i;
                col = j;
                break;
            }
        }
    }

    for (int i = 0; i<8; i++){
        for (int j = 0; j<8 ;j++){
            if ((i == row || j == col) & !(i==row & j==col)){
                d[i][j] = '*';
            }
        }
    }

    for (int i = 0; i<8; i++){
        for (int j = 0; j<8 ;j++){
            printf("%c ", d[i][j]);
        }
        printf("\n");
    }


    return 0;
} 

