
#include "solve.h"
#include <euler/test.h>

void test_pandigital_product() {
  assert(pandigital_product(1, 1) == 0);
  assert(pandigital_product(39, 186) == 7254);
  assert(pandigital_product(40, 186) == 0);
  assert(pandigital_product(38, 186) == 0);
  assert(pandigital_product(39, 185) == 0);
  assert(pandigital_product(39, 187) == 0);
}

void test_solve() {}

