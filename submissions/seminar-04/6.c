#include <stdio.h>

int main(void){
    int N;
    scanf("%d",&N);
    int a[N];
    for (int i=0;i<N;i++){
        scanf("%d",&a[i]);
    }
    int x;
    scanf("%d",&x);
    for(int i=0;i<N;i++){
        if (a[i]==x){
            printf("%d",i);
            return 0;
        }
        
    }
    printf("%d",-1);
    return 0;
}