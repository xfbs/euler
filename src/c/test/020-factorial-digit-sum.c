
#include "020-factorial-digit-sum.h"
#include <euler/test.h>

void test_solve_020() {
  assert(solve_020(1) == 1);
  assert(solve_020(2) == 2);
  assert(solve_020(3) == 6);
  assert(solve_020(4) == 2 + 4);
  assert(solve_020(5) == 1 + 2 + 0);
  assert(solve_020(6) == 7 + 2 + 0);
  assert(solve_020(7) == 5 + 0 + 4 + 0);
  assert(solve_020(8) == 4 + 0 + 3 + 2 + 0);
  assert(solve_020(9) == 3 + 6 + 2 + 8 + 8 + 0);
  assert(solve_020(10) == 3 + 6 + 2 + 8 + 8 + 0 + 0);
  assert(solve_020(11) == 3 + 9 + 9 + 1 + 6 + 8 + 0 + 0);
  assert(solve_020(12) == 4 + 7 + 9 + 0 + 0 + 1 + 6 + 0 + 0);
}


