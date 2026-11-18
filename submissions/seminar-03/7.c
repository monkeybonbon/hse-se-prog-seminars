#include <stdio.h>

int main(void){
    int n, x, min;

    scanf("%d", &n);
    scanf("%d", &min);
    for (int i = 1; i<n; i++){
        scanf ("%d", &x);

        if ( x < min){
            min = x;
        }
    }
    printf("%d\n", min);

    return 0;
}