require 'minitest/autorun'
require_relative '../src/solver'

class SolverTest < MiniTest::Test
  def test_num_to_digits
    assert_equal [1, 2, 3], Solver.num_to_digits_rev(123).reverse
    assert_equal [1, 7, 0, 9], Solver.num_to_digits_rev(1709).reverse
    assert_equal [1], Solver.num_to_digits_rev(1).reverse
    assert_equal [9, 9, 8, 9], Solver.num_to_digits_rev(9989).reverse
  end
end
