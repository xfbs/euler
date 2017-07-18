require 'test_helper'

class SolutionTest < MiniTest::Test
  def setup
  end

  def test_solution
    assert_equal Solution.solve(0), 0
  end

  def test_rectangles
    assert_equal Solution.rects(2, 3), 18
    assert_equal Solution.rects(3, 2), 18
    assert_equal Solution.rects(4, 2), 8 + 6 + 4 + 2 + 4 + 3 + 2 + 1
  end
end
