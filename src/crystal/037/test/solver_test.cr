require "minitest/autorun"
require "../src/solver"

class SolverTest < Minitest::Test
  def test_solve
    assert_equal Solver.solve(1), 23
  end

  def test_is_truncatable_prime
    p = Euler::Prime.new

    assert Solver.is_truncatable_prime?(p, 23)
    assert Solver.is_truncatable_prime?(p, 3797)
    assert Solver.is_truncatable_prime?(p, 37)
    assert !Solver.is_truncatable_prime?(p, 29)
    assert !Solver.is_truncatable_prime?(p, 31)
  end

  def test_prime_iter
    p = Euler::Prime.new
    assert_equal p.iter.select { |n| n == 2 }.first(1).sum, 2
    assert_equal p.iter.select { |n| n == 3 }.first(1).sum, 3
    assert_equal p.iter.select { |n| n == 5 }.first(1).sum, 5
    assert_equal p.iter.select { |n| n == 7 }.first(1).sum, 7
    assert_equal p.iter.select { |n| n == 11 }.first(1).sum, 11
    assert_equal p.iter.select { |n| n == 13 }.first(1).sum, 13
    assert_equal p.iter.select { |n| n == 17 }.first(1).sum, 17
  end
end
