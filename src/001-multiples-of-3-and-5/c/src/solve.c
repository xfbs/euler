#include "solve.h"

uint32_t solve(uint32_t max, uint32_t div1, uint32_t div2) {
  return sum_divisible(max, div1) + sum_divisible(max, div2) -
         sum_divisible(max, lcm(div1, div2));
}

uint32_t sum_divisible(uint32_t max, uint32_t divisor) {
  // smallest number lower than max that is
  // divisible by divisor
  int bound = max - (max % divisor);

  return (bound * ((bound / divisor) + 1)) / 2;
}
