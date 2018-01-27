#include <catch/catch.hpp>
#include <euler/digits.hpp>
#include <euler/iterators.hpp>
using namespace euler;

TEST_CASE("can double digits of a number", "[map_iter]") {
  auto end = digits(0);

  SECTION("for small numbers") {
    auto num = digits(1234);

    auto doub = [](const uint64_t &digit) { return 2 * digit; };

    auto iter = map_iter(num, doub);
    auto nend = map_iter(end, doub);

    REQUIRE(number_from_digits(iter, nend) == 2468);
  }
}
