require 'minitest/autorun'
require_relative '../src/solver'

class SolverTest < MiniTest::Test
  def test_solve
    assert_equal Solver.solve(3), 25
    assert_equal Solver.solve(5),101
  end
end
