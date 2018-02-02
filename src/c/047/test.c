
#include "solve.h"
#include <euler/test.h>

void test_distinct_prime_factors() {
  prime_t p = prime_new();

  assert(distinct_prime_factors(&p, 1, 2) == true);
  assert(distinct_prime_factors(&p, 1, 3) == true);
  assert(distinct_prime_factors(&p, 1, 6) == false);

  assert(distinct_prime_factors(&p, 2, 13) == false);
  assert(distinct_prime_factors(&p, 2, 14) == true);
  assert(distinct_prime_factors(&p, 2, 15) == false);

  assert(distinct_prime_factors(&p, 3, 643) == false);
  assert(distinct_prime_factors(&p, 3, 644) == true);
  assert(distinct_prime_factors(&p, 3, 645) == false);

  for (uint32_t i = 123; i < 23423; i++) {
    for (uint8_t l = 4; l < 10; l++) {
      assert(distinct_prime_factors(&p, l, i) == false);
    }
  }
}

void test_solve_047() {
  assert(solve_047(2) == 14);
  assert(solve_047(3) == 644);
}

