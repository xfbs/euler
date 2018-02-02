require "minitest/autorun"
require "../src/solver"

class SolverTest < Minitest::Test
  def test_solver
    assert_equal Solver.solve(10), 10
    assert_equal Solver.solve(50), 44
  end
end
