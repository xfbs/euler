require "minitest/autorun"
require "../src/euler/math"

class MathTest < Minitest::Test
  def test_factorial
    assert_equal Euler.factorial(0), 1u64
    assert_equal Euler.factorial(1), 1u64
    assert_equal Euler.factorial(2), 1u64*2
    assert_equal Euler.factorial(3), 1u64*2*3
    assert_equal Euler.factorial(4), 1u64*2*3*4
    assert_equal Euler.factorial(5), 1u64*2*3*4*5
    assert_equal Euler.factorial(6), 1u64*2*3*4*5*6
    assert_equal Euler.factorial(7), 1u64*2*3*4*5*6*7
  end

  def test_is_palindrome
    assert Euler.is_palindrome?(1)
    assert Euler.is_palindrome?(10201)
    assert Euler.is_palindrome?(209902)
    assert Euler.is_palindrome?(5, 2)
    assert !Euler.is_palindrome?(1234)
    assert !Euler.is_palindrome?(1121)
    assert !Euler.is_palindrome?(101102)
    assert !Euler.is_palindrome?(32)
  end

  def test_fibonaccis
    assert_equal Euler.fibonacci(1), 1
    assert_equal Euler.fibonacci(2), 1
    assert_equal Euler.fibonacci(3), 2
    assert_equal Euler.fibonacci(4), 3
    assert_equal Euler.fibonacci(5), 5
    assert_equal Euler.fibonacci(6), 8
    assert_equal Euler.fibonacci(7), 13
    assert_equal Euler.fibonacci(8), 21
    assert_equal Euler.fibonacci(9), 34
    assert_equal Euler.fibonacci(10), 55
  end

  def test_pandigital_len_one
    assert_equal Euler.pandigital(len: 1, nth: 0), 1
  end

  def test_pandigital_len_two
    assert_equal Euler.pandigital(len: 2, nth: 0), 12
    assert_equal Euler.pandigital(len: 2, nth: 1), 21
  end

  def test_pandigital_len_three
    assert_equal Euler.pandigital(len: 3, nth: 0), 123
    assert_equal Euler.pandigital(len: 3, nth: 1), 132
    assert_equal Euler.pandigital(len: 3, nth: 2), 213
    assert_equal Euler.pandigital(len: 3, nth: 3), 231
    assert_equal Euler.pandigital(len: 3, nth: 4), 312
    assert_equal Euler.pandigital(len: 3, nth: 5), 321
  end

  def test_pandigital_len_five
    assert_equal Euler.pandigital(len: 5, nth: 0), 12345
    assert_equal Euler.pandigital(len: 5, nth: 1), 12354
    assert_equal Euler.pandigital(len: 5, nth: 2), 12435
    assert_equal Euler.pandigital(len: 5, nth: 3), 12453
    assert_equal Euler.pandigital(len: 5, nth: 4), 12534
    assert_equal Euler.pandigital(len: 5, nth: 5), 12543
  end
end
