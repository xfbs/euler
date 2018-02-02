#define EULER_TEST_MAIN
#include "solve.h"
#include <euler/test.h>

void test_solve() {
  assert(solve(0) == 123456789LL);
  assert(solve(1) == 123456798LL);
  assert(solve(2) == 123456879LL);
  assert(solve(3) == 123456897LL);
  assert(solve(362880) == 1023456789LL);
  assert(solve(362881) == 1023456798LL);
  assert(solve(362882) == 1023456879LL);
  assert(solve(362883) == 1023456897LL);
}

TESTS() { RUN(test_solve); }
