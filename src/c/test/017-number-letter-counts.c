
#include "017-number-letter-counts.h"
#include <euler/test.h>

void test_solve_017() {
  assert(3 == solve_017(1));
  assert(39 == solve_017(10));
  assert(864 == solve_017(100));
}

void test_number_letter_count() {
  assert(3 == number_letter_count(1));
  assert(35 == number_letter_count(3451));
}

