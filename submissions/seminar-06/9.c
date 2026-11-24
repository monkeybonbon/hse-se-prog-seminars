double fast_pow(double x, unsigned n) {
    if (n == 0)
        return 1.0;

    double half = fast_pow(x, n / 2);

    if (n % 2 == 0)
        return half * half;

    return x * half * half;
}