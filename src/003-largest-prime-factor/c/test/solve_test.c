#include "solve.h"
#include <euler/test.h>

void test_solve() { assert(solve(13195) == 29); }

void test_prime() {
  assert(shitty_primality_test(1) == false);
  assert(shitty_primality_test(2) == true);
  assert(shitty_primality_test(3) == true);
  assert(shitty_primality_test(4) == false);
  assert(shitty_primality_test(5) == true);
  assert(shitty_primality_test(6) == false);
  assert(shitty_primality_test(7) == true);
  assert(shitty_primality_test(8) == false);
  assert(shitty_primality_test(9) == false);
  assert(shitty_primality_test(10) == false);
}

TESTS() {
  RUN(test_solve);
  RUN(test_prime);
}
