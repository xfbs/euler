require "minitest/autorun"
require "../src/solver"

class SolverTest < Minitest::Test
  def test_solve
    assert_equal Solver.solve(4), 1634 + 8208 + 9474
  end

  def test_digit_power_sum?
    assert Solver.digit_power_sum?([0, 0, 1, 2, 3, 4], 1234)
    assert Solver.digit_power_sum?([0, 0, 2, 2, 4, 5], 4252)

    assert !Solver.digit_power_sum?([0, 0, 1, 2, 3, 4], 43212)
    assert !Solver.digit_power_sum?([0, 0, 1, 2, 3, 4], 5321)
  end
end
