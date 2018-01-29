#include <algorithm>
#include <cstdint>
#include <numeric>
#include <range/v3/all.hpp>
#pragma once

namespace euler {
// A range that iterates over all the digits in a given number in reverse order.
class reverse_digits : public ranges::view_facade<reverse_digits> {
  friend ranges::range_access;

  // current number
  uint64_t cur = 0;

  // return current digit
  uint64_t read() const { return cur % 10; }

  // check if we have reached the end
  bool equal(ranges::default_sentinel) const { return cur == 0; }

  // advance to next digit
  void next() { cur /= 10; }

public:
  reverse_digits() = default;
  explicit reverse_digits(uint64_t number) : cur(number) {}
};
} // namespace euler
