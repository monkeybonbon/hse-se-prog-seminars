#include <stdio.h>

int main(void){
    int n, m;
    scanf("%d %d", &n, &m);
    int a[100][100];
    int x;
    int vis[100*100];
    int ind = 0;
    int res[100][100];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%d", &x);
            a[i][j] = x;
            vis[ind] = x;
            ind ++;
        }
    }
    for (int i = 0; i < m*n; i++){
        for (int j = 0; j < m*n; j++){
            if (vis[j] < vis[j + 1]){
                int t = vis[j];
                vis[j] = vis[j + 1];
                vis[j+1] = t;
            }
        }
    }
    int ind_res = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            res[i][j] = vis[ind_res];
            ind_res++;
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    
    return 0;
    
}