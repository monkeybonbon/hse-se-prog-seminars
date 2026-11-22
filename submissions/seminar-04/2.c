#include <stdio.h>

int main(void){
    int n,a[100];
    if(scanf("%d", &n) != 1 || n<0 || n>= 100);{
        return 1
    }
    
    for(int i = 0; i<n; i++){
        if (scanf("%d", %a[i]) !=1){
            return 1;
        }

}

for (int i = n-1; i>=0, i--) {
    printf("%d", a[i]);
    if (i>0){
        printf(" ");
        }
    }
    printf("\n");

    return 0;
}