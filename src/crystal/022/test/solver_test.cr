require "minitest/autorun"
require "../src/solver"

class SolverTest < Minitest::Test
  def test_solve
    assert_equal Solver.solve(["A", "Z", "COLIN"]), 1*1 + 2*53 + 3*26
  end

  def test_weight
    assert_equal 1, Solver.weight("A")
    assert_equal 26, Solver.weight("Z")
    assert_equal 53, Solver.weight("COLIN")
  end
end
