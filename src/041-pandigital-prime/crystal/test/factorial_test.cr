require "minitest/autorun"
require "../src/euler/factorial"

class FactorialTest < Minitest::Test
  def test_factorial
    assert_equal Euler.factorial64(0), 1u64
    assert_equal Euler.factorial64(1), 1u64
    assert_equal Euler.factorial64(2), 1u64*2
    assert_equal Euler.factorial64(3), 1u64*2*3
    assert_equal Euler.factorial64(4), 1u64*2*3*4
    assert_equal Euler.factorial64(5), 1u64*2*3*4*5
    assert_equal Euler.factorial64(6), 1u64*2*3*4*5*6
    assert_equal Euler.factorial64(7), 1u64*2*3*4*5*6*7
  end
end
