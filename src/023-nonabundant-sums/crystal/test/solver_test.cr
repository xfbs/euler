require "minitest/autorun"
require "../src/solver"

class SolverTest < Minitest::Test
  def test_solve
    assert_equal Solver.solve(10), 45
    assert_equal Solver.solve(20), 190
    assert_equal Solver.solve(25), 276
    assert_equal Solver.solve(32), 442
  end
end
