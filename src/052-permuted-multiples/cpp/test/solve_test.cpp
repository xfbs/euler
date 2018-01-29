#include "solve.hpp"
#include <catch/catch.hpp>

TEST_CASE("check_permuted_multiple works", "[check_permuted_multiple]") {
  SECTION("with obvious solutions") {
    REQUIRE(check_permuted_multiple(125874, 1, 2));
  }
}
