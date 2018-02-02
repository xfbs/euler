require "minitest/autorun"
require "../src/solver"

class SolverTest < Minitest::Test
  def test_num_to_digits
    assert_equal [1, 2, 3], Solver.num_to_digits_rev(123).reverse
    assert_equal [1, 7, 0, 9], Solver.num_to_digits_rev(1709).reverse
    assert_equal [1], Solver.num_to_digits_rev(1).reverse
    assert_equal [9, 9, 8, 9], Solver.num_to_digits_rev(9989).reverse
  end

  def test_is_permuted_multiple
    assert !Solver.is_permuted_multiple?(123)
    assert !Solver.is_permuted_multiple?(1324)
    assert !Solver.is_permuted_multiple?(43232)
    assert !Solver.is_permuted_multiple?(121231)
    assert !Solver.is_permuted_multiple?(1432)
  end

  def test_solve
    assert Solver.is_permuted_multiple?(Solver.solve)
  end
end
