require "minitest/autorun"
require "../src/euler/divisors"

class DivisorsTest < Minitest::Test
  def test_divisors
    assert_equal Euler.divisors(1).to_a, [1]
    assert_equal Euler.divisors(2).to_a, [1]
    assert_equal Euler.divisors(3).to_a, [1]
    assert_equal Euler.divisors(4).to_a, [1, 2]
    assert_equal Euler.divisors(5).to_a, [1]
    assert_equal Euler.divisors(6).to_a, [1, 2, 3]
    assert_equal Euler.divisors(7).to_a, [1]
    assert_equal Euler.divisors(8).to_a, [1, 2, 4]
    assert_equal Euler.divisors(9).to_a, [1, 3]
    assert_equal Euler.divisors(10).to_a, [1, 2, 5]
    assert_equal Euler.divisors(11).to_a, [1]
    assert_equal Euler.divisors(12).to_a, [1, 2, 6, 3, 4]
    assert_equal Euler.divisors(60).to_a, [1, 2, 30, 3, 20, 4, 15, 5, 12, 6, 10]
  end
end
