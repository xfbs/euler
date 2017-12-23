require "minitest/autorun"
require "../src/solver"

class SolverTest < Minitest::Test
  def test_pandigital_product_sums
    assert_equal Solver.pandigital_product_sums((1..9).to_a), nil
    assert_equal Solver.pandigital_product_sums([3, 9, 1, 8, 6, 7, 2, 5, 4]), [7254]
  end
end
