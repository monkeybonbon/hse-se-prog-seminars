#include <stdio.h>

int main(void) {
   char a[8][8];

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++) {
            scanf("%c", &a[i][j]);
        }
    }

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if (a[i][j] == "R"){
            }
        }
    }

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++) {
            printf("%c", a[i][j]);
        }
    }

    return 0;
}