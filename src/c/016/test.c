#define EULER_TEST_MAIN
#include "solve.h"
#include <euler/test.h>

void test_solve() {
  assert(solve(1) == 2);
  assert(solve(2) == 4);
  assert(solve(3) == 8);
  assert(solve(4) == 1 + 6);
  assert(solve(5) == 3 + 2);
  assert(solve(6) == 6 + 4);
  assert(solve(7) == 1 + 2 + 8);
  assert(solve(8) == 2 + 5 + 6);
  assert(solve(9) == 5 + 1 + 2);
  assert(solve(10) == 1 + 0 + 2 + 4);
  assert(solve(11) == 2 + 0 + 4 + 8);
}

TESTS() { RUN(test_solve); }
