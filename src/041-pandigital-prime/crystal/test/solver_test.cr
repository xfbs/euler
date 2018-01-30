require "minitest/autorun"
require "../src/solver"

class SolverTest < Minitest::Test
  def test_solve
    assert_equal Solver.solve(4), 4231
  end
end
