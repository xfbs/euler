require "minitest/autorun"
require "../src/solver"

class SolverTest < Minitest::Test
  def test_solver
    assert_equal Solver.solve(2), 6
    assert_equal Solver.solve(4), 28
  end
end
