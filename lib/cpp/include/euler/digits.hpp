#include <algorithm>
#include <cstdint>
#include <numeric>
#pragma once

namespace euler {
class digits : public std::iterator<std::forward_iterator_tag, uint64_t,
                                    ptrdiff_t, const uint64_t *, uint64_t> {
  uint64_t num;
  uint64_t pos;

public:
  explicit digits(uint64_t num);
  digits &operator++();
  digits operator++(int);
  bool operator==(digits other) const;
  bool operator!=(digits other) const;
  reference operator*() const;
};

class reverse_digits
    : public std::iterator<std::forward_iterator_tag, uint64_t, ptrdiff_t,
                           const uint64_t *, uint64_t> {
  uint64_t cur;

public:
  explicit reverse_digits(uint64_t num);
  reverse_digits &operator++();
  reverse_digits operator++(int);
  bool operator==(reverse_digits other) const;
  bool operator!=(reverse_digits other) const;
  reference operator*() const;
};

class unique_digits : public reverse_digits {
  uint64_t seen;
  bool saw(uint64_t digit);

public:
  explicit unique_digits(uint64_t num);
  unique_digits &operator++();
  unique_digits operator++(int);
};

template <class InputIt>
using value_type = typename std::iterator_traits<InputIt>::value_type;

template <class InputIt>
uint64_t number_from_digits(InputIt begin, InputIt end) {
  value_type<InputIt> init = 0;
  value_type<InputIt> base = 10;
  auto op = [base](const value_type<InputIt> &a, const value_type<InputIt> &b) {
    return base * a + b;
  };

  return std::accumulate(begin, end, init, op);
}
} // namespace euler
