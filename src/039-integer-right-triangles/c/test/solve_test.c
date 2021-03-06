#define EULER_TEST_MAIN
#include "solve.h"
#include <euler/test.h>

void test_solutions_count() {
  assert(solutions_count(120) == 3);
  assert(solutions_count(12) == 1);
}

void test_solve() { assert(solve(12) == 12); }

TESTS() {
  RUN(test_solutions_count);
  RUN(test_solve);
}
