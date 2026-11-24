static void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void normalize(int *a, int *b, int *c) {
    if (*a > *b)
        swap(a, b);

    if (*b > *c)
        swap(b, c);

    if (*a > *b)
        swap(a, b);
}