static void swap_int(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void normalize(int *a, int *b, int *c) {
    if (*a > *b) {
        swap_int(a, b);
    }
    if (*b > *c) {
        swap_int(b, c);
    }
    if (*a > *b) {
        swap_int(a, b);
    }
}