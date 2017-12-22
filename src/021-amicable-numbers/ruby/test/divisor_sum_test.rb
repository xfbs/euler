require 'minitest/autorun'
require_relative '../src/divisor_sum'

class DivisorSumTest < MiniTest::Test
  def test_divisor_sum
    assert_equal Euler.divisor_sum(2), 1
    assert_equal Euler.divisor_sum(3), 1
    assert_equal Euler.divisor_sum(4), 1+2
    assert_equal Euler.divisor_sum(5), 1
    assert_equal Euler.divisor_sum(6), 1+2+3
    assert_equal Euler.divisor_sum(7), 1
    assert_equal Euler.divisor_sum(8), 1+2+4
    assert_equal Euler.divisor_sum(9), 1+3
    assert_equal Euler.divisor_sum(10), 1+2+5
    assert_equal Euler.divisor_sum(11), 1
    assert_equal Euler.divisor_sum(12), 1+2+3+4+6
    assert_equal Euler.divisor_sum(60), 1+2+3+4+5+6+10+12+15+20+30
  end
end
