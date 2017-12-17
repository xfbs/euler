require "minitest/autorun"
require "../src/solver"

class SolverTest < Minitest::Test
  def test_solution
    assert_equal 2640, Solver.solve(10)
  end
end
