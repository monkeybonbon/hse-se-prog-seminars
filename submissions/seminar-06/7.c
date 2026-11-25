#include <stdio.h>

int second_max(const int a[], size_t n) {
    int m1 = a[0];
    int m2 = 0;
    int flag = 0;

    for (size_t i = 1; i < n; i++) {
        int t = a[i];
        if (!flag && t != m1) {
            m2 = m1 > t ? t : m1;
            m1 = m1 > t ? m1 : t;
            flag = 1;
        } else if (!flag) {
            continue;
        }

        if (t > m1) {
            m2 = m1;
            m1 = t;
        } else if (t > m2 && t != m1) {
            m2 = t;
        }
    }

    return m2;
}

int main(void) {
    int a[4] = {4, 8, 2, 6};
    printf("%d\n", second_max(a, 4));
}
