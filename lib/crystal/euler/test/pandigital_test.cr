require "minitest/autorun"
require "../src/euler/pandigital"

class PandigitalTest < Minitest::Test
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
