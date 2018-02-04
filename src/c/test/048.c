
#include "048.h"
#include <euler/test.h>

void test_solve_048() {
  assert(10405071317 == solve_048(10, 11));
  assert(405071317 == solve_048(10, 10));
  assert(71317 == solve_048(10, 5));
}


