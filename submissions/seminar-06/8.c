#include <stdio.h>

void rotate_right(int a[], size_t n, unsigned x){
    x = x%n;
    int c = 0;
    for (size_t i = 0; c<n; i++){
        size_t curr_i = i;
        int curr_v = a[i];
        do{
            size_t next_i = (curr_i+x)%n;
            int temp = a[next_i];
            a[next_i] = curr_v;
            curr_v = temp;
            curr_i = next_i;
            c++;

        } while(i!=curr_i);
    }
    return;
}

int main(void){
    int a[100];
    size_t n;
    unsigned x;
    scanf("%zu", &n);
    for (int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    scanf("%u", &x);
    rotate_right(a,n,x);
    for (int i=0; i<n; i++){
        printf("%d ",a[i]);
    }

    return 0;
}