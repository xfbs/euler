require "minitest/autorun"
require "../src/solver"

class SolverTest < Minitest::Test
  def setup
  end

  def test_solve
    assert_equal 1, Solver.solve(0)
    assert_equal 2, Solver.solve(1)
    assert_equal 4, Solver.solve(2)
    assert_equal 8, Solver.solve(3)
    assert_equal 7, Solver.solve(4)
    assert_equal 5, Solver.solve(5)
    assert_equal 10, Solver.solve(6)
  end
end
