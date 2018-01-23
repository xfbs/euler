#include "solve.h"
#include <euler/test.h>

void test_solve() {
  assert(solve(0) == 1);
  assert(solve(1) == 1);
  assert(solve(2) == 2);
  assert(solve(3) == 6);
  assert(solve(10) == 2520);
}

TESTS() { RUN(test_solve); }
