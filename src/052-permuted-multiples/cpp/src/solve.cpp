#include "solve.hpp"
#include <euler/digits.hpp>
#include <range/v3/algorithm.hpp>
#include <range/v3/view.hpp>
#include <range/v3/to_container.hpp>
#include <vector>
using namespace ranges;
using namespace euler;

uint64_t solve(uint8_t minmul, uint8_t maxmul) {
  const auto is_permuted_multiple = [minmul, maxmul](int base) {
    return check_permuted_multiple(base, minmul, maxmul);
  };

  auto permuted_multiples = view::ints(1) | view::filter(is_permuted_multiple);

  return front(permuted_multiples);
}

bool check_permuted_multiple(uint64_t base, uint8_t minmul, uint8_t maxmul) {
  auto multiples = view::ints((int)minmul, (int)maxmul + 1)
    | view::transform([base](int mul) { return base * mul; })
    | view::transform([](int num){ return sort_digits(num); });

  auto first = front(multiples);
  auto rest = multiples | view::drop(1);

  const auto same_digits = [first](int number) {
    return first == number;
  };

  return all_of(rest, same_digits);
}

uint64_t sort_digits(uint64_t number) {
  const auto cast_to_u8 = [](uint64_t digit) {
    return (uint8_t) digit;
  };

  auto sorted_digits = to_vector(digits(number) | view::transform(cast_to_u8))
    | action::sort;

  // when reconstituting the digits, we start out with a 1. why? because if the
  // number is 1002, it becomes 0012, indistinguishable from 10002, which
  // becomes 00012. by having a leading 1, these become 10012 and 100012
  // respectively, which means we can differentiate between them.
  // a better solution would be to reverse sort, such that they would become
  // 2100 and 21000, this is left as an exercise for the reader.
  return accumulate(sorted_digits, 1, [](uint64_t memo, uint8_t cur) {
      return 10 * memo + cur;
      });
}
