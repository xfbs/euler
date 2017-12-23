require 'minitest/autorun'
require_relative '../src/solver'

class SolverTest < MiniTest::Test
  def setup
  end

  def test_solver
    assert_equal Solver.solve(2), 6
    assert_equal Solver.solve(4), 28
  end
end
