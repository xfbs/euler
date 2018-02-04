
#include "solve.h"
#include <euler/test.h>
#include <euler/vec.h>

void test_solve_013() {
  vecp_t v = vecp_new(0, NULL);
  vec_push(&v, "1234567890123456789");

  assert(solve_013(&v) == 1234567890LL);
}


