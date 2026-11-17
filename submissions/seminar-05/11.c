#include <stdio.h>

int main(void){
    int n, m;
    scanf("%d %d", &n, &m);
    int a[100][100];
    int start = 1;
    int verh = 0;
    int niz = n - 1;
    int l = 0;
    int r = m - 1;

    while (verh <= niz && l <= r){
        for (int j = l; j <= r; j++){
            a[verh][j] = start;
            start++;
        }
        verh++;
        for (int i = verh; i <= niz; i++){
            a[i][r] = start;
            start++;
        }
        r--;
        if (verh <= niz){
            for (int j = r; j >= l; j--){
                a[niz][j] = start;
                start++;
            }
            niz--;
        }
        if (l <= r){
            for (int i = niz; i >= verh; i--){
                a[i][l] = start;
                start++;
            }
            l++;
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}