
#include "solve.h"
#include <euler/test.h>

void test_solve() {
  assert(solve(2, 20) == 19);
  assert(solve(3, 20) == 38);
  assert(solve(4, 20) == 48);
  assert(solve(5, 20) == 67);
  assert(solve(6, 20) == 86);
  assert(solve(7, 20) == 105);
  assert(solve(8, 20) == 116);
  assert(solve(9, 20) == 126);
  assert(solve(10, 20) == 145);
  assert(solve(11, 20) == 164);
  assert(solve(12, 20) == 183);

  assert(solve(100, 15) == 1307);
}


