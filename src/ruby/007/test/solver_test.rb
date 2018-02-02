require 'minitest/autorun'
require_relative '../src/solver'

class SolverTest < MiniTest::Test
  def test_solve
    assert_equal Solver.solve(1), 2
  end
end
