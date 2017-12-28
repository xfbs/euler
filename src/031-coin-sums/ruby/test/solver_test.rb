require 'minitest/autorun'
require_relative '../src/solver'

class SolverTest < MiniTest::Test
  def test_change
    assert_equal 1, Solver.change(coins: [1], value: 1)
    assert_equal 2, Solver.change(coins: [2, 1], value: 3)
    assert_equal 4, Solver.change(coins: [5, 2, 1], value: 5)
    assert_equal 5, Solver.change(coins: [5, 2, 1], value: 6)
  end
end
