require 'minitest/autorun'
require_relative '../src/solver'

class SolverTest < MiniTest::Test
  def test_solve
    assert_equal 1, Solver.solve(0, 0, 0)
    assert_equal 40755, Solver.solve(200, 100, 100)
  end
end
