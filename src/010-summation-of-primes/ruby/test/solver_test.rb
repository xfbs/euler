require 'minitest/autorun'
require_relative '../src/solver'

class SolverTest < MiniTest::Test
  def test_solve
    assert_equal Solver.solve(100), 1060
    assert_equal Solver.solve(1000), 76127
    assert_equal Solver.solve(3452), 761455
  end
end
