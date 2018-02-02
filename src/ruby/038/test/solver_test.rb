require 'minitest/autorun'
require_relative '../src/solver'

class SolverTest < MiniTest::Test
  def test_check_pandigital
    assert_equal true, Solver.check_pandigital(123_456_789)
    assert_equal true, Solver.check_pandigital(234_567_891)
    assert_equal true, Solver.check_pandigital(345_678_912)
    assert_equal true, Solver.check_pandigital(456_789_123)
    assert_equal true, Solver.check_pandigital(123_678_945)

    assert_equal false, Solver.check_pandigital(1_236_789_451)
    assert_equal false, Solver.check_pandigital(12_367_894)
    assert_equal false, Solver.check_pandigital(182_678_945)
    assert_equal false, Solver.check_pandigital(19)
    assert_equal false, Solver.check_pandigital(1_023_456_789)
    assert_equal false, Solver.check_pandigital(1_236_789)
  end

  def test_check_pandigital_multiple
    assert_equal true, Solver.check_pandigital_multiple(192, 3)[0]
    assert_equal false, Solver.check_pandigital_multiple(191, 3)[0]
  end
end
