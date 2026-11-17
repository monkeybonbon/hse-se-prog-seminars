#include <stdio.h>

int main(void) {
    int a[3][4];
    for (int i=0; i < 3; i++){
        for (int j=0; j < 4; j++){
            scanf("%d", &a[i][j]);
        }
    }
    printf("%s", "Суммы строк: ");
    printf("%d %d %d", (a[0][0] + a[0][1] + a[0][2]+ a[0][3]), (a[1][0] + a[1][1] + a[1][2]+ a[0][3]), );
     
    return 0;
}