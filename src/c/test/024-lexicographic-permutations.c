
#include "024-lexicographic-permutations.h"
#include <euler/test.h>

void test_solve_024() {
  assert(solve_024(0) == 123456789LL);
  assert(solve_024(1) == 123456798LL);
  assert(solve_024(2) == 123456879LL);
  assert(solve_024(3) == 123456897LL);
  assert(solve_024(362880) == 1023456789LL);
  assert(solve_024(362881) == 1023456798LL);
  assert(solve_024(362882) == 1023456879LL);
  assert(solve_024(362883) == 1023456897LL);
}

