#define EULER_TEST_MAIN
#include "solve.h"
#include <euler/test.h>

void test_solve() {
  assert(solve(90) == 44);
  assert(solve(700) == 798);
}

TESTS() { RUN(test_solve); }
