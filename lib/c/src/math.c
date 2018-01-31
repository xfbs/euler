#include <euler/math.h>
#include <math.h>

uint32_t divisor_sum(uint32_t num) {
  uint32_t sum = 0;

  for (uint32_t i = 1; i <= (uint32_t)sqrt(num); i++) {
    if ((num % i) == 0) {
      sum += i;
      if (i != (num / i) && i != 1) {
        sum += (num / i);
      }
    }
  }

  return sum;
}

uint64_t next_even_fibonacci(uint64_t fibo) { return fibo * PHI3 + 0.5; }

uint64_t factorial(uint8_t nth) {
  static uint64_t cache[18] = {0};
  if (nth <= 1)
    return 1;

  if (nth <= 20) {
    if (!cache[nth - 2])
      cache[nth - 2] = factorial(nth - 1) * nth;

    return cache[nth - 2];
  } else {
    // 21! can't be represented in a uint64_t, this is an overflow.
    return 0;
  }
}

uint64_t lcm(uint64_t a, uint64_t b) {
  if (b > a)
    return lcm(b, a);
  return a / gcd(a, b) * b;
}

uint64_t gcd(uint64_t a, uint64_t b) {
  while (b != 0) {
    uint64_t t = b;
    b = a % b;
    a = t;
  }

  return a;
}
