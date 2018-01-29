#include "solve.hpp"
#include <euler/digits.hpp>
#include <range/v3/algorithm.hpp>
#include <range/v3/view.hpp>
using namespace ranges;
using namespace euler;

uint8_t family_size(Prime &primes, uint64_t prime, uint64_t digit) {
  auto is_prime = [&primes](uint64_t num) { return primes.check(num); };

  // replace all occurences of `digit` in `prime` with `replacement`.
  auto replace_digit_with = [prime, digit](uint64_t replacement) {
    auto transformed = digits(prime) | view::replace(digit, replacement);
    return accumulate(transformed, 0, [](uint64_t memo, uint64_t cur) {
      return 10 * memo + cur;
    });
  };

  // generates a list of possible replacements of the digit, skip the digit
  // itself, and from that generate the replaced prime candidates.
  auto members =
      view::ints((int)digit + 1, 10) | view::transform(replace_digit_with);

  // we know that the number itself is prime, so add one to the amount of prime
  // candidates that are prime.
  return 1 + count_if(members, is_prime);
}

bool check_family(Prime &primes, uint64_t prime, uint8_t family) {
  // we are only interested in finding the smallest prime of a family. if we are
  // looking for a 5-family prime, we know that the smallest of the digist must
  // be 10 - 5 = 5. therefore, we can filter the digit replacement candidates
  // like this.
  auto correct_size = [family](uint64_t digit) {
    return digit <= (10 - family);
  };

  return any_of(unique_digits(prime) | view::filter(correct_size),
                [&primes, prime, family](uint64_t digit) {
                  return family == family_size(primes, prime, digit);
                });
}

uint64_t solve(uint8_t family) {
  auto primes = Prime();

  const auto to_prime = [&primes](int nth) -> uint64_t {
    return primes.nth(nth);
  };

  const auto has_family = [&primes, family](uint64_t prime) -> bool {
    return check_family(primes, prime, family);
  };

  // make list of primes, and for each prime check if it has the correct family
  // size
  auto candidates =
      view::ints | view::transform(to_prime) | view::filter(has_family);

  return front(candidates);
}
