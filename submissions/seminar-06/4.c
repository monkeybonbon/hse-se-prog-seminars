#include <stdio.h>

size_t longest_run(const int a[], size_t n) {
  if (n == 0) {
    return 0;
  }
  unsigned long long maxres = 1;
  unsigned long long res = 1;
  for (int i = 0; i < n - 1; i++) {
    if (a[i] == a[i + 1]) {
      res += 1;
      maxres = maxres > res ? maxres : res;
    } else {
      res = 1;
    }
  }
  maxres = maxres > res ? maxres : res;
  return maxres;
}
