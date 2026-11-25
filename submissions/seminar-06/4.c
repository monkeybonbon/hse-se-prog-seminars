size_t longest_run(const int a[], size_t n) {
    int ans = 1;
    int now = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            now++;
        } else {
            now = 1;
        }
        ans = max(ans, now);
    }
    return ans;
}
