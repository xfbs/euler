#include "solve.hpp"
#include <euler/prime.hpp>
#include <euler/digits.hpp>
#include <range/v3/all.hpp>
using namespace ranges;
using namespace euler;

uint8_t family_size(Prime &primes, uint64_t prime, uint64_t digit) {
  auto not_cur_digit = [digit](uint64_t candidate) {
    return digit != candidate;
  };

  auto is_prime = [&primes](uint64_t num) {
    return primes.check(num);
  };

  auto replace_digit_with = [prime, digit](uint64_t replacement) {
    auto replace_digit = [digit, replacement](uint64_t cur) {
      if(cur == digit) {
        return replacement;
      } else {
        return cur;
      }
    };

    auto transformed = digits(prime) | view::transform(replace_digit);
    return accumulate(transformed, 0, [](uint64_t memo, uint64_t cur) {
        return 10 * memo + cur;
    });
  };

  auto members =
    view::ints(1, 10)
    | view::filter(not_cur_digit)
    | view::transform(replace_digit_with);

  return 1 + count_if(members, is_prime);
}

bool check_family(Prime &primes, uint64_t prime, uint8_t family) {
  auto is_family = [&primes, prime, family](uint64_t digit) {
    return family == family_size(primes, prime, digit);
  };

  // FIXME: return early on success?
  return count_if(reverse_digits(prime), is_family) > 0;
}

uint64_t solve(uint8_t family) {
  auto primes = Prime();

  auto to_prime = [&primes](int nth) -> uint64_t { return primes.nth(nth); };

  auto has_family = [&primes, family](uint64_t prime) -> bool {
    return check_family(primes, prime, family);
  };

  auto candidates =
      view::ints | view::transform(to_prime) | view::filter(has_family);

  return front(candidates);
}
