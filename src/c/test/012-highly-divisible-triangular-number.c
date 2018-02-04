
#include "012-highly-divisible-triangular-number.h"
#include <euler/test.h>

void test_factors() {
  prime_t p = prime_new();

  assert(factor_count(&p, 1) == 1);
  assert(factor_count(&p, 2) == 2);
  assert(factor_count(&p, 3) == 2);
  assert(factor_count(&p, 4) == 3);
  assert(factor_count(&p, 5) == 2);
  assert(factor_count(&p, 6) == 4);
  assert(factor_count(&p, 9) == 3);
  assert(factor_count(&p, 36) == 9);
}


