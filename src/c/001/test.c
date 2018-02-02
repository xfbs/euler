
#include "solve.h"
#include <euler/test.h>

void test_solve_001() {
  assert(solve_001(50, 10, 25) == 175);
  assert(solve_001(50, 25, 10) == 175);
  assert(solve_001(55, 10, 25) == 175);
  assert(solve_001(55, 25, 10) == 175);
  assert(solve_001(9, 3, 5) == 23);
}

void test_sum() {
  assert(sum_divisible(10, 3) == 18);
  assert(sum_divisible(10, 5) == 15);
  assert(sum_divisible(22, 7) == 42);
  assert(sum_divisible(43, 51) == 0);
  assert(sum_divisible(50, 10) == 150);
  assert(sum_divisible(50, 25) == 75);
}
