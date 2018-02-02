require "minitest/autorun"
require "../src/solver"

class SolverTest < Minitest::Test
  def test_solve
    assert_equal Solver.solve(["12345678901234", "87654321098765"]), 9999999999
  end
end
