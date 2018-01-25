#include <catch/catch.hpp>
#include <euler/prime.hpp>

TEST_CASE("primes can be allocated", "[Prime]") {
    auto primes = euler::Prime();
}

TEST_CASE("can return any given prime", "[Prime]") {
    auto primes = euler::Prime();

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
