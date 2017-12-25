require 'minitest/autorun'
require_relative '../src/solver'

class SolverTest < MiniTest::Test
  def test_solver
    assert_equal Solver.solve(2), 6
    assert_equal Solver.solve(4), 28
  end

  def test_factor_count
    p = Prime.new
    assert_equal Solver.factor_count(p, 2), 2
    assert_equal Solver.factor_count(p, 4), 3
    assert_equal Solver.factor_count(p, 8), 4
    assert_equal Solver.factor_count(p, 16), 5
    assert_equal Solver.factor_count(p, 64), 7
    assert_equal Solver.factor_count(p, 32), 6

    assert_equal Solver.factor_count(p, 1), 1
    assert_equal Solver.factor_count(p, 3), 2
    assert_equal Solver.factor_count(p, 6), 4
    assert_equal Solver.factor_count(p, 10), 4
    assert_equal Solver.factor_count(p, 15), 4
    assert_equal Solver.factor_count(p, 21), 4
    assert_equal Solver.factor_count(p, 28), 6
  end
end
