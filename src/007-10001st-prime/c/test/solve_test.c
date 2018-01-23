#include "solve.h"
#include <euler/test.h>

void test_solve() {
  assert(solve(1) == 2);
  assert(solve(2) == 3);
  assert(solve(3) == 5);
  assert(solve(4) == 7);
  assert(solve(5) == 11);
}

TESTS() { RUN(test_solve); }
