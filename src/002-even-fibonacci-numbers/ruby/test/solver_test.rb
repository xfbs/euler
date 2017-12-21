require 'minitest/autorun'
require_relative '../src/solver'

class SolverTest < MiniTest::Test
  def setup
  end

  def test_solver
    assert_equal Solver.solve(10), 10
    assert_equal Solver.solve(50), 44
  end
end
