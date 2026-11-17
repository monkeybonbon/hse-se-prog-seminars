#include <stdio.h>
int main(void) {
    int n;
    int m;
    scanf("%d", &n);
    scanf("%d", &m);
    int a[n][m];
    int b[m][n];
    for (int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int x;
            scanf("%d", &x);
            a[i][j] = x;
        }
    }
    for (int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
           b[j][i] = a[i][j];
        }
    }
     for (int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
           printf("%d", b[i][j]);
        }
        printf("\n");
    }
    return 0;
    
}