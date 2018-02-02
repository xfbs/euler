#define EULER_TEST_MAIN
#include "solve.h"
#include <euler/test.h>

void test_solve() {
  assert(solve(2) == 7);
  assert(solve(3) == 12);
  assert(solve(4) == 17);
  assert(solve(5) == 21);
  assert(solve(6) == 26);
  assert(solve(7) == 31);
  assert(solve(8) == 36);
}

TESTS() { RUN(test_solve); }
