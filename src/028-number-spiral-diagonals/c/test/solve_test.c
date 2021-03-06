#define EULER_TEST_MAIN
#include "solve.h"
#include <euler/test.h>

void test_solve() {
  assert(solve(3) == 25);
  assert(solve(5) == 101);
}

TESTS() { RUN(test_solve); }
