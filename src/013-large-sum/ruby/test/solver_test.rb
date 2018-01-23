require 'minitest/autorun'
require_relative '../src/solver'

class SolverTest < MiniTest::Test
  def test_solve
    assert_equal Solver.solve(%w[12345678901234 87654321098765]), 9_999_999_999
  end
end
