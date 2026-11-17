#include <stdio.h>

int main(void){
    int x = 0;
    int s = 0;
    int c = 0;
    scanf("%d", &x);
    for(int i = 0; i < x; i++){
        scanf("%d", &c);
        s += c;
    }
    printf("%d", s);
    return 0;
}    
