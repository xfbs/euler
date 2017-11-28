require 'test_helper'

class SolutionTest < MiniTest::Test
  def setup
  end

  def test_solution
    assert_equal Solution.solve(0), 0
  end

  def test_false
    assert false
  end
end
