require 'minitest/autorun'
require_relative '../src/solver'

class SolverTest < MiniTest::Test
  def test_weight
    assert_equal 1, Solver.weight("A")
    assert_equal 26, Solver.weight("Z")
    assert_equal 53, Solver.weight("COLIN")
  end
end
