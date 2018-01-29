#include <catch/catch.hpp>
#include <euler/digits.hpp>
#include <range/v3/all.hpp>
using namespace euler;
using namespace ranges;

TEST_CASE("returns the reverse digits of a number", "[reverse_digits]") {

  SECTION("zero does not have any digits") {
    auto digits = reverse_digits(0);

    for_each(digits, [](uint64_t digit) {
        REQUIRE(false);
    });

    REQUIRE(digits.begin() == digits.end());
  }

  SECTION("for short numbers") {
    auto digits = reverse_digits(4);
    auto cur = digits.begin();
    auto end = digits.end();
    REQUIRE(*cur == 4);
    REQUIRE(++cur == end);
    REQUIRE(*cur == 0);
    REQUIRE(cur == end);

    digits = reverse_digits(9);
    cur = digits.begin();
    end = digits.end();
    REQUIRE(*cur == 9);
    cur++;
    REQUIRE(*cur == 0);
    REQUIRE(cur == end);
  }

  SECTION("for longer numbers") {
    auto digits = reverse_digits(235465);
    auto cur = digits.begin();
    auto end = digits.end();

    REQUIRE(*cur == 5);
    ++cur;
    REQUIRE(*cur == 6);
    ++cur;
    REQUIRE(*cur == 4);
    ++cur;
    REQUIRE(*cur == 5);
    cur++;
    REQUIRE(*cur == 3);
    cur++;
    REQUIRE(*cur == 2);
    cur++;
    REQUIRE(cur == end);
  }
}
/*
TEST_CASE("returns the digits of a number", "[digits]") {
  auto end = digits(0);

  SECTION("for short numbers") {
    auto cur = digits(4);
    REQUIRE(*cur == 4);
    REQUIRE(++cur == end);
    REQUIRE(cur == end);

    cur = digits(9);
    REQUIRE(*cur == 9);
    REQUIRE(cur++ == digits(9));
    REQUIRE(cur == end);
  }

  SECTION("for longer numbers") {
    auto cur = digits(235465);

    REQUIRE(*cur == 2);
    ++cur;
    REQUIRE(*cur == 3);
    REQUIRE(cur != end);
    cur++;
    REQUIRE(*cur == 5);
    ++cur;
    REQUIRE(*cur == 4);
    cur++;
    REQUIRE(*cur == 6);
    cur++;
    REQUIRE(*cur == 5);
    cur++;
    REQUIRE(cur == end);
  }
}

TEST_CASE("returns the reverse digits of a number", "[reverse_digits]") {
  auto end = reverse_digits(0);

  SECTION("for short numbers") {
    auto cur = reverse_digits(4);
    REQUIRE(*cur == 4);
    REQUIRE(++cur == end);
    REQUIRE(*cur == 0);
    REQUIRE(cur == end);

    cur = reverse_digits(9);
    REQUIRE(*cur == 9);
    REQUIRE(cur++ == reverse_digits(9));
    REQUIRE(*cur == 0);
    REQUIRE(cur == end);
  }

  SECTION("for longer numbers") {
    auto cur = reverse_digits(235465);

    REQUIRE(*cur == 5);
    REQUIRE(++cur == reverse_digits(23546));
    REQUIRE(*cur == 6);
    REQUIRE(cur++ == reverse_digits(23546));
    REQUIRE(*cur == 4);
    ++cur;
    REQUIRE(*cur == 5);
    cur++;
    REQUIRE(*cur == 3);
    cur++;
    REQUIRE(*cur == 2);
    cur++;
    REQUIRE(cur == end);
  }
}

TEST_CASE("returns only unique digits of a number", "[unique_digits]") {
  auto end = unique_digits(0);

  SECTION("for single digits") {
    auto cur = unique_digits(4);
    REQUIRE(*cur == 4);
    REQUIRE(++cur == end);
    REQUIRE(*cur == 0);
  }

  SECTION("for short numbers") {
    auto cur = unique_digits(99);
    REQUIRE(*cur == 9);
    REQUIRE(++cur == end);
    REQUIRE(*cur == 0);
  }

  SECTION("for longer numbers") {
    auto cur = unique_digits(3522659);
    REQUIRE(*cur == 9);
    REQUIRE(++cur == unique_digits(352265));
    REQUIRE(*cur == 5);
    REQUIRE(++cur == unique_digits(35226));
    REQUIRE(*cur == 6);
    REQUIRE(++cur == unique_digits(3522));
    REQUIRE(*cur == 2);
    REQUIRE(++cur == unique_digits(3));
    REQUIRE(*cur == 3);
    REQUIRE(++cur == end);
  }
}

TEST_CASE("turns digits into numbers", "[number_from_digits]") {
  SECTION("with small numbers") {
    REQUIRE(number_from_digits(reverse_digits(567), reverse_digits(0)) == 765);
    REQUIRE(number_from_digits(digits(3579), digits(0)) == 3579);
  }

  SECTION("with large numbers") {
    REQUIRE(number_from_digits(digits(304543580), digits(0)) == 304543580);
    REQUIRE(number_from_digits(reverse_digits(192345), reverse_digits(0)) ==
            543291);
  }
}
*/
