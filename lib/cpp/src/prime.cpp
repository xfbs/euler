#include <cmath>
#include <euler/prime.hpp>

using namespace euler;

Prime::Prime() { primes = {2, 3}; }

uint64_t Prime::nth(size_t pos) {
  while (primes.size() <= pos)
    _next();
  return primes[pos];
}

uint64_t Prime::_next() {
  uint64_t next = _last() + 2;
  while (!_check_fast(next))
    next += 2;
  primes.push_back(next);
  return next;
}

uint64_t Prime::_last() { return primes[primes.size() - 1]; }

bool Prime::_check_fast(uint64_t prime) {
  uint64_t sqrt = std::sqrt(prime);

  for (size_t i = 0; primes[i] <= sqrt; i++) {
    if (prime % primes[i] == 0) {
      return false;
    }
  }

  return true;
}

bool Prime::check(uint64_t prime) {
  if (prime < 2)
    return false;

  uint64_t sqrt = std::sqrt(prime);
  while (_last() <= sqrt)
    _next();

  for (size_t i = 0; primes[i] <= sqrt; i++) {
    if (prime % primes[i] == 0) {
      return false;
    }
  }

  return true;
}

size_t Prime::below(uint64_t prime) {
  while (_last() < prime) {
    if (_next() == prime) {
      return primes.size() - 1;
    }
  }

  auto elem = std::lower_bound(std::begin(primes), std::end(primes), prime);
  return std::distance(std::begin(primes), elem);
}

// TODO: use std::optional<size_t> here?
size_t Prime::which(uint64_t prime) {
  auto n = below(prime);

  if (nth(n) == prime) {
    return n;
  } else {
    return SIZE_MAX;
  }
}

Prime::iterator Prime::begin() { return Prime::iterator(*this, 0); }

Prime::iterator Prime::end() { return Prime::iterator(*this, SIZE_MAX); }

Prime::iterator::iterator(Prime &_primes, size_t _pos)
    : pos(_pos), primes(_primes) {}

bool Prime::iterator::operator==(iterator other) const {
  return pos == other.pos;
}

bool Prime::iterator::operator!=(iterator other) const {
  return pos != other.pos;
}

Prime::iterator::reference Prime::iterator::operator*() const {
  return primes.nth(pos);
}

Prime::iterator &Prime::iterator::operator++() {
  pos++;
  return *this;
}

Prime::primes_view Prime::view() { return Prime::primes_view(*this); }
