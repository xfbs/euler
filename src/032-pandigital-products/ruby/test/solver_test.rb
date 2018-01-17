require 'minitest/autorun'
require_relative '../src/solver'

class SolverTest < MiniTest::Test
  def test_pandigital_product_sums
    assert_nil Solver.pandigital_product_sums((1..9).to_a)
    assert_equal Solver.pandigital_product_sums([3, 9, 1, 8, 6, 7, 2, 5, 4]), [7254]
  end
end
