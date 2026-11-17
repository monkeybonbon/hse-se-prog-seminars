#include <stdio.h>
int main(void){
    int n,m;
    scanf("%d %d", &n, &m);
    int a[n][m];
    for (int i = 0; i<n; i++){
        for (int j = 0; j<m ;j++){
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i<n; i++){
        for (int j = 0; j<m ;j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    int a2[m][n];
    for (int i = 0; i<m; i++){
        for (int j = 0; j<n ;j++){
            a2[i][j] = a[j][i];
        }
    }

    for (int i = 0; i<m; i++){
        for (int j = 0; j<n ;j++){
            printf("%d ", a2[i][j]);
        }
        printf("\n");
    }


    return 0;
} 