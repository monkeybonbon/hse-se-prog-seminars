#include <stdio.h>


int is_sorted(const int a[], size_t n) {
    if (n < 2)
        return 1;                

    size_t mid = n / 2;
    if (a[mid - 1] > a[mid])
        return 0;
    return is_sorted(a, mid) && is_sorted(a + mid, n - mid);
}

int main(void) {
    const int t1[] = {1, 2, 2, 5};
    const int t2[] = {1, 3, 2, 4};
    const int t3[] = {7};

    printf("%d\n", is_sorted(t1, sizeof t1 / sizeof t1[0]));  
    printf("%d\n", is_sorted(t2, sizeof t2 / sizeof t2[0]));  
    printf("%d\n", is_sorted(t3, sizeof t3 / sizeof t3[0])); 
    printf("%d\n", is_sorted(NULL, 0));                       
    return 0;
}