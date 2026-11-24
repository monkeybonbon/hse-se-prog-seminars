#include <stdio.h>
void normalize(int *a, int *b, int *c) {
    if (*a > *b) {
        int t = *b;
        *b = *a;
        *a = t;
    }
    if (*b > *c) {
        int t = *c;
        *c = *b;
        *b = t;
    }
    if (*a > *b) {
        int t = *b;
        *b = *a;
        *a = t;
    }

}
int main(void) {
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);
    normalize(&a, &b, &c);
    printf("%d %d %d\n", a, b, c);
    return 0;
}