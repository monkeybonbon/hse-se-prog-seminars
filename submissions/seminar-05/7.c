#include <stdio.h>

int main(void){
    int n,m;
    scanf("%d %d,&n,&m");
    int a[n][m];
    int trans[m][n];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            trans[j][i] = a[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", trans[i][j]);
        }
        printf("\n");
    }
    return 0;
}