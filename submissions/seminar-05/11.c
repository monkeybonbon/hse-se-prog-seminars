#include <stdio.h>
int main(void){
    int n, m;
    scanf("%d %d",&n, &m);
    int a[n*m];
    int el = 1;
    int top = 0, bot = 0, left = 0, right = 0;
    while (el<=m*n){
        for (int i = left; (i<m-right && el<=n*m); i++){
            a[top*m+i] = el++;
        }
        top++;

        for (int i = top; (i<n-bot  && el<=n*m); i++){
            a[i*m+m-1 - right] = el++;
        }
        right++;

        for (int i = m-right-1; (i>=left  && el<=n*m); i--){
            a[(n-bot-1)*m+i] = el++;
        }
        bot++;
        
        for (int i = n-1-bot; (i>=top  && el<=n*m); i--){
            a[m*i+left] = el++;
        }
        left++;
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            printf("%d ", a[i*m+j]);
        }
        printf("\n");
    }
    
    return 0;
} 
