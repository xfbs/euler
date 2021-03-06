require "minitest/autorun"
require "../src/solver"

class SolverTest < Minitest::Test
  def test_solution
    assert_equal Solver.solve(0), 1
    assert_equal Solver.solve(1), 1
    assert_equal Solver.solve(2), 2
    assert_equal Solver.solve(3), 6
    assert_equal Solver.solve(10), 2520
  end
end
