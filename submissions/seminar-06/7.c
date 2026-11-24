#include <stdio.h>

int second_max(const int a[], size_t n)
{
    int max = a[0];
    size_t i = 1;

    while (a[i] == max)
        i++;

    int max2 = a[i];

    if (max2 > max) {
        int temp = max;
        max = max2;
        max2 = temp;
    }

    for (i = 0; i < n; i++) {
        if (a[i] > max) {
            max2 = max;
            max = a[i];
        }

        else if (a[i] < max && a[i] > max2) {
            max2 = a[i];
        }
    }

    return max2;
}


int main(void) {
    int a[] = {1, 2, 3, 4, 4};
    printf("%d\n", second_max(a, sizeof(a)/sizeof(a[0])));
}