#include <algorithm>
#include <catch/catch.hpp>
#include <euler/prime.hpp>
using namespace euler;

TEST_CASE("primes can be allocated", "[Prime]") { auto primes = Prime(); }

TEST_CASE("can return any given prime", "[Prime]") {
  auto primes = Prime();

  SECTION("initial primes are available") {
    REQUIRE(primes.nth(0) == 2);
    REQUIRE(primes.nth(1) == 3);
  }

  SECTION("further primes can be generated") {
    REQUIRE(primes.nth(2) == 5);
    REQUIRE(primes.nth(3) == 7);
  }

  SECTION("generation does not need to be sequential") {
    REQUIRE(primes.nth(7) == 19);
    REQUIRE(primes.nth(10) == 31);
    REQUIRE(primes.nth(5) == 13);
  }
}

TEST_CASE("which returns the index of the prime", "[Prime]") {
  auto primes = Prime();

  SECTION("of primes that exist") {
    REQUIRE(primes.which(0) == SIZE_MAX);
    REQUIRE(primes.which(1) == SIZE_MAX);
    REQUIRE(primes.which(2) == 0);
    REQUIRE(primes.which(3) == 1);
  }

  SECTION("of primes that have to be generated") {
    REQUIRE(primes.which(4) == SIZE_MAX);
    REQUIRE(primes.which(5) == 2);
    REQUIRE(primes.which(6) == SIZE_MAX);
    REQUIRE(primes.which(7) == 3);
    REQUIRE(primes.which(8) == SIZE_MAX);
    REQUIRE(primes.which(9) == SIZE_MAX);
    REQUIRE(primes.which(10) == SIZE_MAX);
    REQUIRE(primes.which(11) == 4);
    REQUIRE(primes.which(12) == SIZE_MAX);
    REQUIRE(primes.which(13) == 5);
    REQUIRE(primes.which(14) == SIZE_MAX);
    REQUIRE(primes.which(15) == SIZE_MAX);
    REQUIRE(primes.which(16) == SIZE_MAX);
    REQUIRE(primes.which(17) == 6);
    REQUIRE(primes.which(18) == SIZE_MAX);
    REQUIRE(primes.which(19) == 7);
    REQUIRE(primes.which(20) == SIZE_MAX);
  }
}

TEST_CASE("can check if a number is prime or not", "[Prime]") {
  auto primes = Prime();

  SECTION("of small primes") {
    REQUIRE(primes.check(0) == false);
    REQUIRE(primes.check(1) == false);
    REQUIRE(primes.check(2) == true);
    REQUIRE(primes.check(3) == true);
    REQUIRE(primes.check(4) == false);
    REQUIRE(primes.check(5) == true);
    REQUIRE(primes.check(6) == false);
    REQUIRE(primes.check(7) == true);
    REQUIRE(primes.check(8) == false);
    REQUIRE(primes.check(9) == false);
    REQUIRE(primes.check(10) == false);
    REQUIRE(primes.check(11) == true);
  }

  SECTION("of larger primes") {
    REQUIRE(primes.check(53) == true);
    REQUIRE(primes.check(55) == false);
  }
}

TEST_CASE("can find out how many primes are smaller than a number", "[Prime]") {
  auto primes = Prime();

  SECTION("with small primes") {
    REQUIRE(primes.below(0) == 0);
    REQUIRE(primes.below(1) == 0);
    REQUIRE(primes.below(2) == 0);
    REQUIRE(primes.below(3) == 1);
    REQUIRE(primes.below(4) == 2);
    REQUIRE(primes.below(5) == 2);
    REQUIRE(primes.below(6) == 3);
    REQUIRE(primes.below(7) == 3);
    REQUIRE(primes.below(8) == 4);
    REQUIRE(primes.below(9) == 4);
    REQUIRE(primes.below(10) == 4);
    REQUIRE(primes.below(20) == 8);
  }

  SECTION("with large primes") { REQUIRE(primes.below(100) == 25); }
}

TEST_CASE("the operators that are supplied work", "[Prime]") {
  auto primes = Prime();

  SECTION("when using find_if") {
    REQUIRE(*std::find_if(
                std::begin(primes), std::end(primes),
                [](const uint64_t &candidate) { return candidate == 7; }) == 7);
    REQUIRE(*std::find_if(std::begin(primes), std::end(primes),
                          [](const uint64_t &candidate) {
                            return candidate > 11;
                          }) == 13);
  }
}
