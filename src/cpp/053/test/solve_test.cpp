#include "solve.hpp"
#include <catch/catch.hpp>

TEST_CASE("approximate ncr works well enough", "[approximate_ncr]") {
  SECTION("for small numbers") {
    REQUIRE(approximate_ncr(5, 3) == 10.0);
    REQUIRE(approximate_ncr(5, 5) == 1.0);
  }

  SECTION("for larger numbers") {
    REQUIRE(approximate_ncr(23, 10) == 1144066.0);
  }
}

TEST_CASE("count_for_n finds amount of r for n that yield a value > target", "[count_for_n]") {
  SECTION("for small n") {
    REQUIRE(count_for_n(1, 1000000) == 0);
    REQUIRE(count_for_n(5, 1000000) == 0);
    REQUIRE(count_for_n(9, 1000000) == 0);
    REQUIRE(count_for_n(15, 1000000) == 0);
    REQUIRE(count_for_n(21, 1000000) == 0);
    REQUIRE(count_for_n(22, 1000000) == 0);
  }

  SECTION("for medium sized n") {
    REQUIRE(count_for_n(23, 1000000) == 4);
    REQUIRE(count_for_n(24, 1000000) == 7);
    REQUIRE(count_for_n(25, 1000000) == 10);
    REQUIRE(count_for_n(26, 1000000) == 11);
    REQUIRE(count_for_n(27, 1000000) == 12);
  }
}

TEST_CASE("solve returns num of nCr > limit for n <= maxn", "[solve]") {
  REQUIRE(solve(100, 10000) == 4431);
  REQUIRE(solve(88, 123456) == 3163);
  REQUIRE(solve(56, 999000) == 959);
}
