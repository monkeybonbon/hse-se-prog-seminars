#include <stdio.h>
#define q int
#define w double
#define e char
#define ql long long int
#define qu unsigned int

q zxc(q n, q m, q a[n][m]){
    for (q i = 0; i < n; i++){
        for (q j = 0; j < m; j++){
            if ((j != m-1 && a[i][j] < a[i][j+1]) || (j == m-1 && i != n-1 && a[i][j] < a[i+1][0])){
                return 0;
            }
        }
    }
    return 1;
}

q main(void) {
    q n,m;
    scanf("%d %d", &n, &m);
    q a[n][m];
    for (q i = 0; i < n; i++){
        for (q j = 0; j < m; j++){
            scanf("%d", &a[i][j]);
        }
    }
    while(zxc(n, m, a) != 1){
        for (q i = 0; i < n; i++){
            for (q j = 0; j < m; j++){
                if (j != m-1 && a[i][j] < a[i][j+1]){
                    q s = a[i][j];
                    a[i][j] = a[i][j+1];
                    a[i][j+1] = s;
                }
                else if (j == m-1 && i != n-1 && a[i][j] < a[i+1][0]){
                    q s = a[i][j];
                    a[i][j] = a[i+1][0];
                    a[i+1][0] = s;
                }
            }
        }    
    }
    for (q i = 0; i < n; i++){
        for (q j = 0; j < m; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}