
#include "031-coin-sums.h"
#include <euler/test.h>

void test_solve_031() {
  assert(solve_031(0) == 1);
  assert(solve_031(1) == 1);
  assert(solve_031(2) == 2);
  assert(solve_031(3) == 2);
  assert(solve_031(4) == 3);
  assert(solve_031(5) == 4);
  assert(solve_031(6) == 5);
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

