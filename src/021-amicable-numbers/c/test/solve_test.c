#define EULER_TEST_MAIN
#include "solve.h"
#include <euler/test.h>

void test_amicable_pair() {
  assert(amicable_pair(10) == 0);
  assert(amicable_pair(220) == 284);
  assert(amicable_pair(284) == 220);
}

TESTS() { RUN(test_amicable_pair); }
