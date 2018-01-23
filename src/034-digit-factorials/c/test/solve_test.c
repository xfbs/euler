#include "solve.h"
#include <euler/factorial.h>
#include <euler/test.h>

void test_is_curious_number() {
  uint64_t factorials[10];
  for (uint8_t i = 0; i < 10; i++)
    factorials[i] = factorial(i);

  assert(true == is_curious_number(factorials, 145));
  assert(false == is_curious_number(factorials, 10));
  assert(false == is_curious_number(factorials, 12));
  assert(false == is_curious_number(factorials, 19));
  assert(false == is_curious_number(factorials, 9));
}

void test_solve() {
  assert(0 == solve(0));
  assert(0 == solve(1));
  assert(0 == solve(2));
  assert(0 == solve(3));
  assert(145 == solve(145));
}

TESTS() {
  RUN(test_is_curious_number);
  RUN(test_solve);
}
