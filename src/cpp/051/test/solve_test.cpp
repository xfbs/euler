#include "solve.hpp"
#include <catch/catch.hpp>
using namespace euler;

TEST_CASE("solve returns correct result", "[solve]") {
  SECTION("with small family sizes") {
    REQUIRE(solve(4) == 2);
    REQUIRE(solve(1) == 7);
  }

  SECTION("with larger family sizes") {
    REQUIRE(solve(6) == 13);
    REQUIRE(solve(7) == 56003);
  }
}

TEST_CASE("family_size works correctly", "[family_size]") {
  auto primes = Prime();

  SECTION("with small numbers") {
    REQUIRE(family_size(primes, 2, 2) == 4); // 2, 3, 5, 7
    REQUIRE(family_size(primes, 13, 1) == 6); // 13, 23, 43, 53, 73, 83
    REQUIRE(family_size(primes, 11, 1) == 1);
  }

  SECTION("with larger numbers") {
    REQUIRE(family_size(primes, 56003, 0) == 7);
  }
}

TEST_CASE("check_family works correctly", "[check_family]") {
  auto primes = Prime();

  SECTION("with small numbers") {
    REQUIRE(check_family(primes, 2, 4));
    REQUIRE(check_family(primes, 11, 1));
  }

  SECTION("with larger numbers") {
    REQUIRE(check_family(primes, 56003, 7));
  }
}
