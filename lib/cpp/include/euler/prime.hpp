#include <algorithm>
#include <cstdint>
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

public:
  Prime();
  uint64_t nth(size_t pos);
  bool check(uint64_t prime);
  size_t which(uint64_t prime);
  size_t below(uint64_t num);

  iterator begin();
  iterator end();
};
} // namespace euler
