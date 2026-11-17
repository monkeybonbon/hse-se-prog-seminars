void zero16(int *p) {
    for (int i = 0; i < 16; i++) {
        p[i - 5] = 0;
    }
}
