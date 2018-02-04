
#include "039.h"
#include <euler/test.h>

void test_solutions_count() {
  assert(solutions_count(120) == 3);
  assert(solutions_count(12) == 1);
}

void test_solve_039() { assert(solve_039(12) == 12); }

