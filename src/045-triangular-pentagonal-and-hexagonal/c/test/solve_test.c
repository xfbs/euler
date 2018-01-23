#include "solve.h"
#include <euler/test.h>

void test_solve() {
  assert(solve(0, 0, 0) == 1);
  assert(solve(200, 100, 100) == 40755);
}

TESTS() { RUN(test_solve); }
