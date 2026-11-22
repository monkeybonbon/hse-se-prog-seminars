#include <stdio.h>

int main(void) {
    int a, b;

    scanf("%d %d", &a, &b);

    int* a_ptr = &a;
    int* b_ptr = &b;

    int temp = *a_ptr;
    *a_ptr = *b_ptr;
    *b_ptr = temp;

    printf("%d %d\n", a, b);

    return 0;
}
