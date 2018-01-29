#include <algorithm>
#include <cstdint>
#include <numeric>
#include <range/v3/all.hpp>
#pragma once

namespace euler {
// A range that iterates over all the digits in a given number.
class digits : public ranges::view_facade<digits> {
  friend ranges::range_access;

  // current number
  uint64_t cur = 0;
  uint64_t pos = 0;

  // return current digit
  uint64_t read() const { return cur / pos; }

  // check if we have reached the end
  bool equal(ranges::default_sentinel) const { return cur == 0; }

  // advance to next digit
  void next() {
    cur %= pos;
    pos /= 10;
  }

public:
  digits() = default;
  explicit digits(uint64_t number) : cur(number) {
    if (cur != 0) {
      pos = 1;
    }

    while ((pos * 10) <= cur) {
      pos *= 10;
    }
  }
};

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

// A range that iterates over all the unique digits of a number in unspecified
// order.
class unique_digits : public ranges::view_facade<unique_digits> {
  friend ranges::range_access;

  // current number
  uint64_t cur = 0;
  uint64_t seen = 0;

  // return current digit
  uint64_t read() const { return cur % 10; }

  // check if we have reached the end
  bool equal(ranges::default_sentinel) const { return cur == 0; }

  // advance to next digit
  void next() {
    cur /= 10;

    while(cur != 0 && saw(read())) {
      cur /= 10;
    }
  }

  bool saw(uint64_t digit) {
    bool res = seen & (1 << digit);
    seen |= (1 << digit);
    return res;
  }

public:
  unique_digits() = default;
  explicit unique_digits(uint64_t number) : cur(number) {
    saw(read());
  }
};
} // namespace euler
