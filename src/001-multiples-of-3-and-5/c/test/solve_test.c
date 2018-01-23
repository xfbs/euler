#include "solve.h"
#include <euler/test.h>

void test_solve() {
  assert(solve(50, 10, 25) == 175);
  assert(solve(50, 25, 10) == 175);
  assert(solve(55, 10, 25) == 175);
  assert(solve(55, 25, 10) == 175);
  assert(solve(9, 3, 5) == 23);
}

void test_sum() {
  assert(sum_divisible(10, 3) == 18);
  assert(sum_divisible(10, 5) == 15);
  assert(sum_divisible(22, 7) == 42);
  assert(sum_divisible(43, 51) == 0);
  assert(sum_divisible(50, 10) == 150);
  assert(sum_divisible(50, 25) == 75);
}

TESTS() {
  RUN(test_sum);
  RUN(test_solve);
}
