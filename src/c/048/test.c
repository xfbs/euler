
#include "solve.h"
#include <euler/test.h>

void test_solve() {
  assert(10405071317 == solve(10, 11));
  assert(405071317 == solve(10, 10));
  assert(71317 == solve(10, 5));
}


