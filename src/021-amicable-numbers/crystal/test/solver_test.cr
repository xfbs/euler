require "minitest/autorun"
require "../src/solver"

class SolverTest < Minitest::Test
  def test_divisor_sum
    assert_equal Solver.divisor_sum(2), 1
    assert_equal Solver.divisor_sum(3), 1
    assert_equal Solver.divisor_sum(4), 1+2
    assert_equal Solver.divisor_sum(5), 1
    assert_equal Solver.divisor_sum(6), 1+2+3
    assert_equal Solver.divisor_sum(7), 1
    assert_equal Solver.divisor_sum(8), 1+2+4
    assert_equal Solver.divisor_sum(9), 1+3
    assert_equal Solver.divisor_sum(10), 1+2+5
    assert_equal Solver.divisor_sum(11), 1
    assert_equal Solver.divisor_sum(12), 1+2+3+4+6
    assert_equal Solver.divisor_sum(60), 1+2+3+4+5+6+10+12+15+20+30
  end

  def test_amicable_pair
    assert_equal Solver.amicable_pair(220), 284
    assert_equal Solver.amicable_pair(284), 220
    assert_nil Solver.amicable_pair(221)
    assert_nil Solver.amicable_pair(285)
  end

  def test_solve
    assert_equal Solver.solve(10), 0
    assert_equal Solver.solve(20), 0
    assert(Solver.solve(285) == (220+284))
  end
end
