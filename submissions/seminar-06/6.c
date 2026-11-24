void normalize(int *a, int *b, int *c) {
    if (*a >= *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    if (*b >= *c) {
        int temp = *b;
        *b = *c;
        *c = temp;
    }

    if (*a >= *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    printf("%d %d %d", *a, *b, *c);
}