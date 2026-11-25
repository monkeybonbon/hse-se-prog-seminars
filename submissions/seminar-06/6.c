void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void normalize(int *a, int *b, int *c) {
    if (*b < *a) {
        swap(a, b);
    }
    if (*c < *a) {
        swap(a, c);
    }
    if (*c < *b) {
        swap(b, c);
    }
}
