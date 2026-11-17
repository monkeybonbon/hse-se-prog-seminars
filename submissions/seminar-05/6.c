#include <stdio.h>

int main(void) {
    int a[3][4];
    int i,j,s;
    for(i=0;i<3;i++){
        for(j=0;j<4;j++) scanf("%d",&a[i][j]);
    }
    printf("Суммы строк:");
    for(i=0;i<3;i++){
        s=0;
        for(j=0;j<4;j++){
            s+=a[i][j];
        }
        printf(" %d",s);
    }
    printf("\nСуммы столбцов:");



    for(j=0;j<4;j++){
        s=0;
        for(i=0;i<3;i++) s+=a[i][j];
        printf(" %d",s);
    }
    printf("\n");
    return 0;
}
