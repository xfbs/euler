#include "solve.hpp"
#include <range/v3/all.hpp>
#include <euler/prime.hpp>
using namespace ranges;
using namespace euler;

uint64_t solve(uint8_t family) {
  auto primes = Prime();

  auto to_prime = [&primes](int nth) -> uint64_t {
    return primes.nth(nth);
  };

  auto has_family = [](uint64_t prime) -> bool {
    return true;
  };

  auto candidates =
    view::ints
    | view::transform(to_prime)
    | view::filter(has_family);

  return front(candidates);
}
