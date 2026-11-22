#include <stdio.h>

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int arr[n][m];

    int l = 0, r = m - 1, t = 0, b = n - 1;

    int c = 1;
    while (l <= r && t <= b) {
        for (int j = l; j <= r; ++j)
            arr[t][j] = c++;

        if (t == b) {
            break;
        }

        for (int i = t + 1; i <= b; ++i)
            arr[i][r] = c++;

        if (l == r) {
            break;
        }

        for (int j = r - 1; j >= l; --j)
            arr[b][j] = c++;

        for (int i = b - 1; i > t; --i)
            arr[i][l] = c++;

        ++l;
        --r;
        ++t;
        --b;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
