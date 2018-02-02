require 'minitest/autorun'
require_relative '../src/solver'

class SolverTest < MiniTest::Test
  def test_palindrome
    assert_equal Solver.palindrome(123, false), 123_321
    assert_equal Solver.palindrome(123, true), 12_321
    assert_equal Solver.palindrome(12, false), 1221
    assert_equal Solver.palindrome(12, true), 121
    assert_equal Solver.palindrome(6435, false), 64_355_346
    assert_equal Solver.palindrome(6435, true), 6_435_346
    assert_equal Solver.palindrome(1, false), 11
  end

  def test_factorizable
    assert_equal Solver.factorizable(234 * 345, 234, 345), true
    assert_equal Solver.factorizable(234 * 345, 23, 34), false
    assert_equal Solver.factorizable(999_999, 100, 999), false
  end

  def test_solve
    assert_equal Solver.solve(2), 9009
  end
end
