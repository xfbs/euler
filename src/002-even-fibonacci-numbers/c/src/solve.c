#include "solve.h"

int solve(int max) {
  uint64_t cur = 2;
  uint64_t sum = 0;

  while (cur < max) {
    sum += cur;
    cur = next_even_fibonacci(cur);
  }

  return (int)sum;
}
