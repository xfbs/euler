#include <algorithm>
#include <cstdint>
#include <range/v3/view_facade.hpp>
#include <vector>
#pragma once

namespace euler {
class Prime {
  std::vector<uint64_t> primes;
  uint64_t _next();
  uint64_t _last();
  bool _check_fast(uint64_t prime);

  class iterator
      : public std::iterator<std::random_access_iterator_tag, uint64_t, size_t,
                             const uint64_t *, uint64_t> {
    size_t pos;
    Prime &primes;

  public:
    explicit iterator(Prime &primes, size_t pos);
    iterator &operator++();
    iterator &operator--();
    iterator operator++(int);
    iterator operator--(int);
    bool operator==(iterator other) const;
    bool operator!=(iterator other) const;
    reference operator*() const;
  };

  class primes_view : public ranges::view_facade<primes_view> {
    friend ranges::range_access;

    // current number
    size_t pos = 0;
    Prime &primes;

    // return current digit
    uint64_t read() const { return primes.nth(pos); }

    // check if we have reached the end
    bool equal(ranges::default_sentinel) const { return false; }

    // advance to next digit
    void next() { pos += 1; }

  public:
    // reverse_digits() = default;
    explicit primes_view(Prime &p) : primes(p) {}
  };

public:
  Prime();
  uint64_t nth(size_t pos);
  bool check(uint64_t prime);
  size_t which(uint64_t prime);
  size_t below(uint64_t num);

  iterator begin();
  iterator end();
  primes_view view();
};
} // namespace euler
