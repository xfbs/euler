#include "025-1000digit-fibonacci-number.h"
#include <math.h>

uint32_t solve_025(uint32_t max) {
  double phi = (1.0 + sqrt(5)) / 2;

  double sum1 = 0.5 * log(5);
  double sum2 = (max - 1) * log(10);
  return ceil((sum1 + sum2) / log(phi));
}
