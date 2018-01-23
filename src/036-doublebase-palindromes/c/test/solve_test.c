#include "solve.h"
#include <euler/test.h>

void test_is_palindrome() {
  assert(is_palindrome(11, 10));
  assert(is_palindrome(22, 10));
  assert(is_palindrome(131, 10));
  assert(is_palindrome(12321, 10));
  assert(is_palindrome(404, 10));
  assert(is_palindrome(581185, 10));
  assert(is_palindrome(98889, 10));
  assert(!is_palindrome(10, 10));
  assert(!is_palindrome(100, 10));

  assert(is_palindrome(3, 2));
  assert(is_palindrome(5, 2));
  assert(is_palindrome(9, 2));
  assert(is_palindrome(17, 2));
  assert(is_palindrome(21, 2));
  assert(!is_palindrome(2, 2));
  assert(!is_palindrome(4, 2));
  assert(is_palindrome(3, 2));
  assert(is_palindrome(73, 2));
}

TESTS() { RUN(test_is_palindrome); }
