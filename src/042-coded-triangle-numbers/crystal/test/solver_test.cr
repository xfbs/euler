require "minitest/autorun"
require "../src/solver"

class SolverTest < Minitest::Test
  def test_solution
    assert_equal Solver.solve(["SKY"]), 1
    assert_equal Solver.solve(["SKY", "HAMBURGER"]), 1
    assert_equal Solver.solve(["HAMBURGER"]), 0
  end
end
