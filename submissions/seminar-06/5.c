unsigned digit_sum(unsigned n) {
    if (n < 10) {
        return n;
    }
    return n % 10 + digit_sum(n / 10);
}
