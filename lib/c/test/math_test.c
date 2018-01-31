#include <euler/math.h>
#include <euler/test.h>

void test_lcm() {
  // gcd of primes a and b is always a*b
  assert(lcm(3, 5) == 15);
  assert(lcm(5, 13) == 65);

  assert(lcm(2, 10) == 10);
  assert(lcm(3, 10) == 30);
  assert(lcm(10, 25) == 50);
}

void test_gcd() {
  assert(gcd(3, 5) == 1);
  assert(gcd(5, 13) == 1);
  assert(gcd(2, 10) == 2);
  assert(gcd(5, 10) == 5);
  assert(gcd(10, 25) == 5);
}

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

void test_divisor_sum() {
  assert(divisor_sum(2) == 1);
  assert(divisor_sum(3) == 1);
  assert(divisor_sum(4) == 1 + 2);
  assert(divisor_sum(5) == 1);
  assert(divisor_sum(6) == 1 + 2 + 3);
  assert(divisor_sum(7) == 1);
  assert(divisor_sum(8) == 1 + 2 + 4);
  assert(divisor_sum(9) == 1 + 3);
  assert(divisor_sum(10) == 1 + 2 + 5);
  assert(divisor_sum(11) == 1);
  assert(divisor_sum(12) == 1 + 2 + 3 + 4 + 6);
  assert(divisor_sum(220) == 284);
  assert(divisor_sum(284) == 220);
}


void test_fibos() {
  assert(next_even_fibonacci(2) == 8);
  assert(next_even_fibonacci(8) == 34);
  assert(next_even_fibonacci(34) == 144);
  assert(next_even_fibonacci(144) == 610);

  for (uint64_t cur = 2; cur < 1000000; cur = next_even_fibonacci(cur)) {
    // make sure it's even
    assert((cur & 1) == 0);
  }
}

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

void test_palin() {
  assert(is_palindrome(101) == true);
  assert(is_palindrome(123) == false);
  assert(is_palindrome(404) == true);
  assert(is_palindrome(767) == true);
  assert(is_palindrome(999) == true);
  assert(is_palindrome(424) == true);
  assert(is_palindrome(11) == true);
  assert(is_palindrome(18) == false);
  assert(is_palindrome(1095901) == true);
  assert(is_palindrome(1047402) == false);
  assert(is_palindrome(6060) == false);
  assert(is_palindrome(123454321) == true);
}

TESTS() {
  RUN(test_fibos);
  RUN(test_lcm);
  RUN(test_gcd);
  RUN(test_factorial);
  RUN(test_speed);
  RUN(test_overflow);
  RUN(test_divisor_sum);
  RUN(test_nth_pandigital);
  RUN(test_palin);
}

