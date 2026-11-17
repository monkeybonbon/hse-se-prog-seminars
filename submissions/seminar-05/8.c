#include <stdio.h>
int main() {
    char a[8][9];
    int x,y;
    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
            scanf(" %c", a[i][j]);
    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
            if(a[i][j]=='R'){
                x=i;
                y=j;
            }
    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
        if((i==x||j==y)&&a[i][j]!='R')
            a[i][j]='*';
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++)
            printf("%c", a[i][j]);
        printf("\n");
    }
    return 0;
}