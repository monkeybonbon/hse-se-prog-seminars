#include <stdio.h>

unsigned digit_sum(unsigned n) {
  if (n == 0) {
    return 0;
  }
  if (1 <= n && n <= 9) {
    return n;
  } else {
    return (n % 10) + digit_sum(n / 10);
  }
}
