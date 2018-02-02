
#include "solve.h"
#include <euler/test.h>

void test_num_to_digits() {
  digits_t d;

  d = num_to_digits(0);
  assert(d.count == 0);

  d = num_to_digits(1);
  assert(d.count == 1);
  assert(d.digits[0] == 1);

  d = num_to_digits(123);
  assert(d.count == 3);
  assert(d.digits[2] == 1);
  assert(d.digits[1] == 2);
  assert(d.digits[0] == 3);

  d = num_to_digits(34897562);
  assert(d.count == 8);
  assert(d.digits[7] == 3);
  assert(d.digits[6] == 4);
  assert(d.digits[5] == 8);
  assert(d.digits[4] == 9);
  assert(d.digits[3] == 7);
  assert(d.digits[2] == 5);
  assert(d.digits[1] == 6);
  assert(d.digits[0] == 2);
}

void test_is_permuted_multiple() {
  assert(!is_permuted_multiple(123));
  assert(!is_permuted_multiple(12131));
  assert(!is_permuted_multiple(5421));
  assert(!is_permuted_multiple(9234));
  assert(!is_permuted_multiple(3425));
  assert(!is_permuted_multiple(34329));
}

void test_solve() { assert(is_permuted_multiple(solve())); }

