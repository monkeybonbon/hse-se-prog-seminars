#include <stdio.h>

int main(void){
    int n,m;
    scanf("%d %d", &n, &m);
    int a[100][100];
    int x;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%d", &x);
            a[i][j] = x;
        }
    }
    int res[100][100];
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            res[i][j] = a[j][i];
        }
    }
    for (int i = 0; i < m; i++){
        for (int j = 0; j< n; j++){
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}