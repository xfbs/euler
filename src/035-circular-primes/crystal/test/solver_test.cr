require "minitest/autorun"
require "../src/solver"

class SolverTest < Minitest::Test
  def test_solve
    assert_equal Solver.solve(10), 4
    assert_equal Solver.solve(100), 13
  end

  def test_circular
    assert_equal Solver.circular([15, 51], 15), [0, 1]
  end
end
