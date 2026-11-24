#include <stdio.h>

size_t longest_run(const int a[], size_t n) {
    int k_sch = 0;
    size_t m_max = 0;

    for (size_t i = 1; i < n; i++) {
        if (a[i-1] == a[i]) {
            k_sch++;
            if (k_sch >= m_max) m_max = k_sch;
        } else {
            k_sch = 0;
        }
    }

    return m_max + 1;
}

int main (void) {
    int b[] = {1, 1, 2, 2, 2, 3, 4, 4, 4, 4, 4, 5, 5};
    size_t l = 13;
    printf("%d", longest_run(b, l));
    return 0;
}