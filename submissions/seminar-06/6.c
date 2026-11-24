static void swap_if_greater(int *x, int *y) {
    if (*x > *y) {
        int temp = *x;
        *x = *y;
        *y = temp;
    }
}

void normalize(int *a, int *b, int *c) {
    swap_if_greater(a, b);
    swap_if_greater(a, c);
    swap_if_greater(b, c);
}