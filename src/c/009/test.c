
#include "solve.h"
#include <euler/test.h>

void test_solve() { assert(60 == solve(12)); }

void test_is_pythagorean_triplet() {
  assert(is_pythagorean_triplet(3, 4, 5) == true);
  assert(is_pythagorean_triplet(3, 4, 6) == false);
  assert(is_pythagorean_triplet(4, 3, 5) == false);
  assert(is_pythagorean_triplet(20, 21, 29) == true);
  assert(is_pythagorean_triplet(48, 55, 73) == true);
  assert(is_pythagorean_triplet(48, 55, 74) == false);
}

