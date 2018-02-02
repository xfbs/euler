require 'minitest/autorun'
require_relative '../src/solver'

class SolverTest < MiniTest::Test
  def test_sum_divisible
    assert_equal Solver.sum_divisible(10, 3), 3 + 6 + 9
    assert_equal Solver.sum_divisible(15, 5), 5 + 10 + 15
  end

  def test_solve
    assert_equal Solver.solve(10, 2, 3), 2 + 3 + 4 + 6 + 8 + 9 + 10
  end
end
