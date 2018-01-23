#include "solve.h"
#include <euler/test.h>

void test_solve() {
  assert(solve(1) == 1);
  assert(solve(2) == 2);
  assert(solve(3) == 6);
  assert(solve(4) == 2 + 4);
  assert(solve(5) == 1 + 2 + 0);
  assert(solve(6) == 7 + 2 + 0);
  assert(solve(7) == 5 + 0 + 4 + 0);
  assert(solve(8) == 4 + 0 + 3 + 2 + 0);
  assert(solve(9) == 3 + 6 + 2 + 8 + 8 + 0);
  assert(solve(10) == 3 + 6 + 2 + 8 + 8 + 0 + 0);
  assert(solve(11) == 3 + 9 + 9 + 1 + 6 + 8 + 0 + 0);
  assert(solve(12) == 4 + 7 + 9 + 0 + 0 + 1 + 6 + 0 + 0);
}

TESTS() { RUN(test_solve); }
