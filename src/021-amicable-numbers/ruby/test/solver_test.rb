require 'minitest/autorun'
require_relative '../src/solver'

class SolverTest < MiniTest::Test
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
