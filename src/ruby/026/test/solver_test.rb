require 'minitest/autorun'
require_relative '../src/solver'

class SolverTest < MiniTest::Test
  def test_solve
    assert_equal 7, Solver.solve(10)
    assert_equal 3, Solver.solve(4)
  end

  def test_reciprocal_cycle
    assert_equal 0, Solver.reciprocal_cycle(2)
    assert_equal 1, Solver.reciprocal_cycle(3)
    assert_equal 6, Solver.reciprocal_cycle(7)
  end
end
