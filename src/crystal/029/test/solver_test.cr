require "minitest/autorun"
require "../src/solver"

class SolverTest < Minitest::Test
  def setup
  end

  def test_solver
    assert_equal Solver.solve(5), 15
  end
end
