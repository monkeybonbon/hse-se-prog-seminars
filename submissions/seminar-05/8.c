#include <stdio.h>
int main() {
    char a[8][8];
    int i1, i2;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            scanf(" %c", &a[i][j]);
            if (a[i][j] == 'R') {
                i1 = i;
                i2 = j;
            } 
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i == i1 || j == i2) && (i != i1 || j != i2)) {
                a[i][j] = '*';
            } 
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", a[i][j]); 
        }
        printf("\n");
    }
    return 0;
}