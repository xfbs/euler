require 'minitest/autorun'
require_relative '../src/solver'

class SolverTest < MiniTest::Test
  def test_solve
    assert_equal [1, 2, 3], Solver.solve([1, 2, 3], 0)
    assert_equal [1, 3, 2], Solver.solve([1, 2, 3], 1)
    assert_equal [2, 1, 3], Solver.solve([1, 2, 3], 2)
    assert_equal [2, 3, 1], Solver.solve([1, 2, 3], 3)
    assert_equal [3, 1, 2], Solver.solve([1, 2, 3], 4)
    assert_equal [3, 2, 1], Solver.solve([1, 2, 3], 5)
  end
end
