#include <stdio.h>
int main() {
    int n,m;
    int a[100][100];
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%d", &a[i][j]);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            for(int x=i+1; x<n; x++)
                for(int y=j+1; y<m; y++)
                    if(a[i][j]>a[x][y]){
                        int t=a[i][j];
                        a[i][j]=a[x][y];
                        a[x][y]=t;
                    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            printf("%d ", a[i][j]);
    }
    return 0;
}