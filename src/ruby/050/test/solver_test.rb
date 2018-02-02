require 'minitest/autorun'
require_relative '../src/solver'

class SolverTest < MiniTest::Test
  def test_solver
    assert_equal Solver.solve(100), 41
    assert_equal Solver.solve(1000), 953
  end
end
