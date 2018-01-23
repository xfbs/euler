#include "solve.h"
#include <euler/test.h>

void test_quadratic_prime_run() {
  prime_t p = prime_new();

  assert(40 == quadratic_prime_run(&p, 1, 41));
  assert(41 == quadratic_prime_run(&p, -1, 41));
  assert(80 == quadratic_prime_run(&p, -79, 1601));
  assert(0 == quadratic_prime_run(&p, -120, 45));
  assert(2 == quadratic_prime_run(&p, 9, 13));

  prime_free(&p);
}

void test_solve() {
  assert(-126479 == solve(1700));
  assert(-41 == solve(42));
}

TESTS() {
  RUN(test_quadratic_prime_run);
  RUN(test_solve);
}
