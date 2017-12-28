require 'minitest/autorun'
require_relative '../src/solver'

class SolverTest < MiniTest::Test
  def test_solution
    assert_equal Solver.solve(5), 15
  end
end
