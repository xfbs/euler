#include "solve.h"
#include <euler/test.h>

void test_solve() {
  vec_t v = vec_new(0, NULL);
  vec_push(&v, "1234567890123456789");

  assert(solve(&v) == 1234567890LL);
}

TESTS() { RUN(test_solve); }
