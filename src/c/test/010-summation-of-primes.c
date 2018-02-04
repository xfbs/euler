
#include "010-summation-of-primes.h"
#include <euler/test.h>

void test_solve_010() {
  assert(solve_010(10) == (2 + 3 + 5 + 7));
  assert(solve_010(20) == (2 + 3 + 5 + 7 + 11 + 13 + 17 + 19));
  assert(solve_010(30) == (2 + 3 + 5 + 7 + 11 + 13 + 17 + 19 + 23 + 29));
}


