
#include "034.h"
#include <euler/math.h>
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

void test_solve_034() {
  assert(0 == solve_034(0));
  assert(0 == solve_034(1));
  assert(0 == solve_034(2));
  assert(0 == solve_034(3));
  assert(145 == solve_034(145));
}

