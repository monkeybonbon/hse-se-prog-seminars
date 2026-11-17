#include <stdio.h>
#define w char
#define q int
q main(void) {
    w s[8][8];
    q x = -1, y = -1;
    for (q i=0; i < 8; i++){
        for (q j=0; j < 8; j++){
            scanf(" %c", &s[i][j]);
            if (s[i][j] == 'R'){
                x = i;
                y = j;
            }
        }
    }
    for (q i=0; i < 8; i++){
        for (q j=0; j < 8; j++){
            if ((i == x || j == y) && s[i][j] != 'R'){
                s[i][j] = '*';
            }
            printf("%c", s[i][j]);
        }
        printf("\n");
    }
    return 0;
}