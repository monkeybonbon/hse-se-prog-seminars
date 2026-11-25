int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int second_max(const int a[], size_t n) {
    int Max1 = a[0];
    for (int i = 0; i < n; i++) {
        Max1 = max(Max1, a[i]);
    }
    int Max2 = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (a[i] > Max2 && a[i] != Max1) {
            Max2 = a[i];
        }
    }
    return Max2;
}
