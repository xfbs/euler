require 'minitest/autorun'
require_relative '../src/solver'

class SolverTest < MiniTest::Test
  def test_weight
    assert_equal 1, Solution.weight("A")
    assert_equal 26, Solution.weight("Z")
    assert_equal 53, Solution.weight("COLIN")
  end
end
