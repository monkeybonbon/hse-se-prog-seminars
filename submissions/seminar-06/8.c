#include <stdio.h>
void rotate_right(int a[], int n, int x) {
    int sd = x % n;
    for (int s = 0; s < sd; s++) {
        int temp = a[n - 1];
        for (int j = n - 1; j > 0; j -= 1) {
            a[j] = a[j - 1];
        }
        a[0] = temp;
    }
}
int main(void) {
    int n;
    int x;
    printf("Vvedite razmer massiva: ");
    scanf("%d", &n);
    printf("Vvedite sdvig: ");
    scanf("%d", &x);
    printf("Vvedite sam massiv: \n");
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    rotate_right(a, n, x);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}