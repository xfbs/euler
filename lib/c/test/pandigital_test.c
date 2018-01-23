#include <euler/pandigital.h>
#include <euler/test.h>

void test_nth_pandigital() {
  assert(1234 == nth_pandigital(4, 0));
  assert(1243 == nth_pandigital(4, 1));
  assert(1324 == nth_pandigital(4, 2));
  assert(1342 == nth_pandigital(4, 3));
  assert(1423 == nth_pandigital(4, 4));
  assert(1432 == nth_pandigital(4, 5));
  assert(2134 == nth_pandigital(4, 6));
  assert(2143 == nth_pandigital(4, 7));
  assert(2314 == nth_pandigital(4, 8));
  assert(2341 == nth_pandigital(4, 9));
  assert(2413 == nth_pandigital(4, 10));
  assert(2431 == nth_pandigital(4, 11));
  assert(3124 == nth_pandigital(4, 12));
  assert(3142 == nth_pandigital(4, 13));
  assert(3214 == nth_pandigital(4, 14));
  assert(3241 == nth_pandigital(4, 15));
  assert(3412 == nth_pandigital(4, 16));
  assert(3421 == nth_pandigital(4, 17));
  assert(4123 == nth_pandigital(4, 18));
  assert(4132 == nth_pandigital(4, 19));
  assert(4213 == nth_pandigital(4, 20));
  assert(4231 == nth_pandigital(4, 21));
  assert(4312 == nth_pandigital(4, 22));
  assert(4321 == nth_pandigital(4, 23));

  assert(12345 == nth_pandigital(5, 0));
  assert(54321 == nth_pandigital(5, 119));
}

TESTS() { RUN(test_nth_pandigital); }
