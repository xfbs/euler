#include "001-multiples-of-3-and-5.h"
#include <euler/math.h>

uint32_t solve_001(uint32_t max, uint32_t div1, uint32_t div2) {
  return sum_divisible(max, div1) + sum_divisible(max, div2) -
         sum_divisible(max, lcm(div1, div2));
}

uint32_t sum_divisible(uint32_t max, uint32_t divisor) {
  // smallest number lower than max that is
  // divisible by divisor
  int bound = max - (max % divisor);

  return (bound * ((bound / divisor) + 1)) / 2;
}

const char *solve001(void *data) {
  uint32_t max = 999;
  uint32_t div1 = 3;
  uint32_t div2 = 5;

  static char result[256];
  sprintf(result, "%i", solve_001(max, div1, div2));
  return result;
}
