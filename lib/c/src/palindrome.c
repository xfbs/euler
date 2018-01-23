#include "euler/palindrome.h"

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
