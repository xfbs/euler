#include "solve.h"
#include <euler/test.h>

void test_solve() {
  assert(solve(10) == (2 + 3 + 5 + 7));
  assert(solve(20) == (2 + 3 + 5 + 7 + 11 + 13 + 17 + 19));
  assert(solve(30) == (2 + 3 + 5 + 7 + 11 + 13 + 17 + 19 + 23 + 29));
}

TESTS() { RUN(test_solve); }
