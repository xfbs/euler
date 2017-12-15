require "minitest/autorun"
require "../src/solver"

class SolverTest < Minitest::Test
  def setup
  end

  def test_change
    assert_equal 1, Solver.change([1], 1)
    assert_equal 2, Solver.change([2, 1], 3)
    assert_equal 4, Solver.change([5, 2, 1], 5)
    assert_equal 5, Solver.change([5, 2, 1], 6)
  end
end
