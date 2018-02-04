
#include "solve.h"
#include <euler/test.h>

void test_check_fraction() {
  assert(check_fraction(4, 9, 9, 8));
  assert(check_fraction(1, 6, 6, 4));
  assert(!check_fraction(3, 0, 5, 0));
  assert(!check_fraction(1, 2, 3, 4));
}

void test_solve_033() { assert(solve_033() > 1); }

