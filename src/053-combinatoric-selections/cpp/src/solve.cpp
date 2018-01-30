#include "solve.hpp"
#include <range/v3/distance.hpp>
#include <range/v3/numeric/accumulate.hpp>
#include <range/v3/utility/functional.hpp>
#include <range/v3/view/drop_while.hpp>
#include <range/v3/view/iota.hpp>
#include <range/v3/view/take_while.hpp>
#include <range/v3/view/transform.hpp>
using namespace ranges;

uint64_t solve(uint32_t maxn, uint64_t target) {
  const auto to_count = [target](int n) { return count_for_n(n, target); };

  auto counts = view::ints(0, (int)maxn + 1) | view::transform(to_count);

  return accumulate(counts, 0);
}

uint64_t count_for_n(uint32_t n, uint64_t target) {
  const auto to_ncr = [n](int r) { return approximate_ncr(n, r); };

  const auto hits_target = [target](double val) { return val >= target; };

  auto numbers = view::ints(0, (int)n + 1) | view::transform(to_ncr) |
                 view::drop_while(not_fn(hits_target)) |
                 view::take_while(hits_target);

  return distance(numbers);
}

double approximate_ncr(uint32_t n, uint32_t r) {
  double res = 1.0;
  uint32_t enlim = r;
  uint32_t delim = n - r;

  if ((n - r) > r) {
    enlim = n - r;
    delim = r;
  }

  for (uint32_t en = enlim + 1; en <= n; en++) {
    res *= en;
  }

  for (uint32_t de = 1; de <= delim; de++) {
    res /= de;
  }

  return res;
}
