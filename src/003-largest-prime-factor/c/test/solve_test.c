#include "solve.h"
#include <euler/test.h>

void test_solve() { assert(solve(13195) == 29); }

TESTS() {
  RUN(test_solve);
}
