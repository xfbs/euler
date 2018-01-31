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
  static uint64_t cache[19] = {0};
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


uint32_t nth_pandigital(uint8_t n, uint32_t nth) {
  // the finished pandigital
  uint32_t num = 0;

  // which digits are taken
  uint32_t taken = 0;

  while (n) {
    num *= 10;

    // which of the remaining digits we will take
    uint8_t choice = nth / factorial(n - 1);
    nth -= choice * factorial(n - 1);

    // find the remaining digit
    uint8_t digit = 0;
    while (choice != 0) {
      if (!(taken & (1 << digit)))
        choice--;
      digit++;
    }

    while (taken & (1 << digit)) {
      digit++;
    }

    // mark this digit as used
    taken |= 1 << digit;

    // digits are zero-indexed, but we treat '1' as first digit
    digit++;
    num += digit;
    n--;
  }

  return num;
}

bool is_palindrome(uint64_t num) {
  // reverse the number and compare against itself
  uint64_t original = num;
  uint64_t reversed = 0;

  while (num != 0) {
    reversed *= 10;
    reversed += num % 10;
    num /= 10;
  }

  return original == reversed;
}
