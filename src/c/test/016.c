
#include "solve.h"
#include <euler/test.h>

void test_solve_016() {
  assert(solve_016(1) == 2);
  assert(solve_016(2) == 4);
  assert(solve_016(3) == 8);
  assert(solve_016(4) == 1 + 6);
  assert(solve_016(5) == 3 + 2);
  assert(solve_016(6) == 6 + 4);
  assert(solve_016(7) == 1 + 2 + 8);
  assert(solve_016(8) == 2 + 5 + 6);
  assert(solve_016(9) == 5 + 1 + 2);
  assert(solve_016(10) == 1 + 0 + 2 + 4);
  assert(solve_016(11) == 2 + 0 + 4 + 8);
}


