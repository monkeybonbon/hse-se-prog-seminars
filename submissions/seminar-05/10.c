#include <stdio.h>
#define q int
#define w double
#define e char
#define ql long long int
#define qu unsigned int
q main(void) {
    q n;
    scanf("%d", &n);
    q a[n][n];
    for (q i = 0; i < n; i++){
        for (q j = 0; j < n; j++){
            scanf("%d", &a[i][j]);
        }
    }
    for (q i=0; i < n; i++){
        for (q j=i+1; j < n; j++){
            q s = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = s;
        }
    }
    for (q i=0; i < n; i++){
        for (q j=0; j < n/2; j++){
            q s = a[i][j];
            a[i][j] = a[i][n-j-1];
            a[i][n-j-1] = s;
        }
    }
    for (q i = 0; i < n; i++){
        for (q j = 0; j < n; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}