#define EULER_TEST_MAIN
#include "solve.h"
#include <euler/test.h>

void test_solve() {
  assert(solve(0) == 1);
  assert(solve(1) == 1);
  assert(solve(2) == 2);
  assert(solve(3) == 2);
  assert(solve(4) == 3);
  assert(solve(5) == 4);
  assert(solve(6) == 5);
}

void test_change() {
  uint32_t coins1[] = {1, 0};
  uint32_t coins2[] = {2, 1, 0};
  uint32_t coins3[] = {5, 2, 1, 0};
  uint32_t coins4[] = {5, 2, 0};

  assert(change(coins1, 5, 0) == 1);
  assert(change(coins1, 2, 0) == 1);

  assert(change(coins2, 1, 0) == 1);
  assert(change(coins2, 2, 0) == 2);
  assert(change(coins2, 3, 0) == 2);
  assert(change(coins2, 4, 0) == 3);

  assert(change(coins3, 5, 0) == 4);
  assert(change(coins3, 6, 0) == 5);

  assert(change(coins4, 1, 0) == 0);
  assert(change(coins4, 2, 0) == 1);
  assert(change(coins4, 3, 0) == 0);
  assert(change(coins4, 4, 0) == 1);
  assert(change(coins4, 5, 0) == 1);
}

TESTS() {
  RUN(test_solve);
  RUN(test_change);
}
