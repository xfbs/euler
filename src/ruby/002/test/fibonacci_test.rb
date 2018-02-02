require 'minitest/autorun'
require_relative '../src/fibonacci'

class PrimeTest < MiniTest::Test
  def setup; end

  def test_fibonaccis
    assert_equal Fibonacci.nth(1), 1
    assert_equal Fibonacci.nth(2), 1
    assert_equal Fibonacci.nth(3), 2
    assert_equal Fibonacci.nth(4), 3
    assert_equal Fibonacci.nth(5), 5
    assert_equal Fibonacci.nth(6), 8
    assert_equal Fibonacci.nth(7), 13
    assert_equal Fibonacci.nth(8), 21
    assert_equal Fibonacci.nth(9), 34
    assert_equal Fibonacci.nth(10), 55
  end
end
