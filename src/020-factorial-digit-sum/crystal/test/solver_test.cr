require "minitest/autorun"
require "../src/solver"

class SolverTest < Minitest::Test
  def test_solve
    assert_equal Solver.solve(0), 1
    assert_equal Solver.solve(1), 1
    assert_equal Solver.solve(2), 2
    assert_equal Solver.solve(3), 6
    assert_equal Solver.solve(4), 6
    assert_equal Solver.solve(5), 3
    assert_equal Solver.solve(6), 9
    assert_equal Solver.solve(7), 9
    assert_equal Solver.solve(8), 9

    assert_equal Solver.solve(40), 189
  end
end
