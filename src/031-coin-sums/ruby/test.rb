require 'minitest/autorun'
require_relative 'solution'

class SolutionTest < MiniTest::Test
  def setup
  end

  def test_change
    assert_equal 1, Solution.change(coins: [1], value: 1)
    assert_equal 2, Solution.change(coins: [2, 1], value: 3)
    assert_equal 4, Solution.change(coins: [5, 2, 1], value: 5)
    assert_equal 5, Solution.change(coins: [5, 2, 1], value: 6)
  end
end
