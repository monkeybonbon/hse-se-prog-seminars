#include <stdio.h>

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    
    int* a_ptr = &a;
    int* b_ptr = &b;
    int c = *b_ptr;
    c = *a_ptr;
    *a_ptr = *b_ptr;
    *b_ptr = c;
    printf("%d %d", a, b);
    return 0;
}
