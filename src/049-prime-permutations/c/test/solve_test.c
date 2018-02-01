#define EULER_TEST_MAIN
#include "solve.h"
#include <euler/test.h>

void test_permutations() {
  assert(true == permutations(1234, 2341, 3412));
  assert(false == permutations(123, 2103, 2013));
}

TESTS() { RUN(test_permutations); }
