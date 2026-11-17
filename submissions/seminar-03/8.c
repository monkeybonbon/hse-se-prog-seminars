#include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j++){
            if(i == j && i + j == n-1)
                printf("%c", 'X');
            else if(i == j)
                printf("%c", '\\');
            else if(i + j == n-1)
                printf("%c", '/');
            else
                printf("%c", '-');
        }
        printf("%c", '\n');
    }
    return 0;
}
