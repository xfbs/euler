#include <euler/factorial.h>
#include <euler/test.h>

void test_factorial() {
  assert(1 == factorial(0));
  assert(1 == factorial(1));
  assert(2 == factorial(2));
  assert(6 == factorial(3));
  assert(24 == factorial(4));
  assert(120 == factorial(5));
  assert(720 == factorial(6));
  assert(5040 == factorial(7));
  assert(40320 == factorial(8));
  assert(3628800 == factorial(10));
  assert(1307674368000LL == factorial(15));
}

void test_speed() {
  for (uint32_t i = 0; i < 1000000; i++) {
    assert(factorial(i % 20) <= factorial((i % 20) + 1));
  }
}

void test_overflow() {
  assert(factorial(21) == 0);
  assert(factorial(22) == 0);
  assert(factorial(100) == 0);
}

TESTS() {
  RUN(test_factorial);
  RUN(test_speed);
  RUN(test_overflow);
}
