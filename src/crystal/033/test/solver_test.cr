require "minitest/autorun"
require "../src/solver"

class SolverTest < Minitest::Test
  def setup
  end

  def test_solve
    assert_equal true, Solver.check_fraction(4, 9, 9, 8)
    assert_equal false, Solver.check_fraction(3, 0, 5, 0)
  end
end
