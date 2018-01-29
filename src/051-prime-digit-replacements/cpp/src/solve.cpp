#include "solve.hpp"
#include <range/v3/all.hpp>
#include <euler/prime.hpp>
using namespace ranges;
using namespace euler;

uint64_t solve(uint8_t family) {
  auto primes = Prime();

  const auto to_prime = [&primes](int nth) -> uint64_t {
    return primes.nth(nth);
  };

  const auto candidates =
    view::ints
    | view::transform(to_prime);

  auto has_family = [&primes, family](uint64_t prime) -> bool {
    return true;
  };

  auto match = find_if(candidates, has_family);

  return *match;
}
