require "minitest/autorun"
require "../src/solver"

class SolverTest < Minitest::Test
  def setup
  end

  def test_solve
    assert_equal Solver.solve(10_u32), 9
  end
end
