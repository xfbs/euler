require "minitest/autorun"
require "../src/solver"

class SolverTest < Minitest::Test
  def test_solver
    assert_equal Solver.solve(2), 7
    assert_equal Solver.solve(3), 12
    assert_equal Solver.solve(4), 17
    assert_equal Solver.solve(5), 21
    assert_equal Solver.solve(6), 26
    assert_equal Solver.solve(7), 31
    assert_equal Solver.solve(8), 36
  end
end
