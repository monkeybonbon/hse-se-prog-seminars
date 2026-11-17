#include <stdio.h>

int main(void){
    int n,m;
    scanf("%d %d", &n, &m);
    int nn = n*m;

    int a[nn];
    for (int i = 0; i < nn; i++){
        scanf("%d", &a[i]);
    }

    int k = 0;
    int s = 0;

    for (int j = 0; j < (nn - 1); j++){
        for (int i = 0; i < (nn - 1); i++){
            if (a[i] < a[i+1]){
                s = a[i + 1];
                a[i + 1] = a[i];
                a[i] = s;
                k += 1;
            }
        }

        if (k == 0){
                break; // функцию брейк нагуглила, можно было и без оптимизации, но так красивее
            }
        k = 0;
    }

    return 0;
}