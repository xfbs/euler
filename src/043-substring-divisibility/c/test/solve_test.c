#define EULER_TEST_MAIN
#include "solve.h"
#include <euler/test.h>

void test_pandigital() {
  assert(0 == pandigital(306, 357, 289));
  assert(0 == pandigital(410, 293, 560));
  assert(1406357289LL == pandigital(406, 357, 289));
}

TESTS() { RUN(test_pandigital); }
