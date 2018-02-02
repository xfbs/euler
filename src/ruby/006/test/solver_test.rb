require 'minitest/autorun'
require_relative '../src/solver'

class SolverTest < MiniTest::Test
  def test_solution
    assert_equal 2640, Solver.solve(10)
  end
end
