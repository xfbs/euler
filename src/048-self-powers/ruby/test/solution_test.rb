require 'test_helper'

class SolutionTest < MiniTest::Test
  def setup
  end

  def test_solution
    assert_equal Solution.solve(10, 1),            7
    assert_equal Solution.solve(10, 2),           17
    assert_equal Solution.solve(10, 3),          317
    assert_equal Solution.solve(10, 4),         1317
    assert_equal Solution.solve(10, 5),        71317
    assert_equal Solution.solve(10, 6),        71317
    assert_equal Solution.solve(10, 7),      5071317
    assert_equal Solution.solve(10, 8),      5071317
    assert_equal Solution.solve(10, 9),    405071317
    assert_equal Solution.solve(10, 10),   405071317
    assert_equal Solution.solve(10, 11), 10405071317
  end
end
