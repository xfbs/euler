
#include "solve.h"
#include <euler/test.h>

void test_solve_029() {
  assert(solve_029(2, 20) == 19);
  assert(solve_029(3, 20) == 38);
  assert(solve_029(4, 20) == 48);
  assert(solve_029(5, 20) == 67);
  assert(solve_029(6, 20) == 86);
  assert(solve_029(7, 20) == 105);
  assert(solve_029(8, 20) == 116);
  assert(solve_029(9, 20) == 126);
  assert(solve_029(10, 20) == 145);
  assert(solve_029(11, 20) == 164);
  assert(solve_029(12, 20) == 183);

  assert(solve_029(100, 15) == 1307);
}


