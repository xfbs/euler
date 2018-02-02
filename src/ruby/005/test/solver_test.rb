require 'minitest/autorun'
require_relative '../src/solver'

class SolverTest < MiniTest::Test
  def test_solution
    assert_equal Solver.solve(0), 1
    assert_equal Solver.solve(1), 1
    assert_equal Solver.solve(2), 2
    assert_equal Solver.solve(3), 6
    assert_equal Solver.solve(10), 2520
  end
end
