require "minitest/autorun"
require "../src/euler/fibonacci"

class SolverTest < Minitest::Test
  def test_fibonaccis
    assert_equal Euler.fibonacci(1), 1
    assert_equal Euler.fibonacci(2), 1
    assert_equal Euler.fibonacci(3), 2
    assert_equal Euler.fibonacci(4), 3
    assert_equal Euler.fibonacci(5), 5
    assert_equal Euler.fibonacci(6), 8
    assert_equal Euler.fibonacci(7), 13
    assert_equal Euler.fibonacci(8), 21
    assert_equal Euler.fibonacci(9), 34
    assert_equal Euler.fibonacci(10), 55
  end
end
