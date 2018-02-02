require "minitest/autorun"
require "../src/solver"

class SolverTest < Minitest::Test
  def setup
  end

  def test_solve
    assert_equal Solver.solve(3), 25
    assert_equal Solver.solve(5), 101
  end
end
