#include <stdio.h>

int main(void) {
    char a[8][8];
    int x,y;
    scanf("%d %d",&x,&y);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            a[i][j]=".";
        }
    }
    a[x][y]="R";

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (a[i][j] == '.' && (i == x || j == y)) {
                a[i][j] = '*';
            }
        }
    }
    return 0;
}
