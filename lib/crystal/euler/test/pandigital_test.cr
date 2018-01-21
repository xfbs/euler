require "minitest/autorun"
require "../src/euler/pandigital"

class PandigitalTest < Minitest::Test
  def test_pandigital
    # length one
    assert_equal Euler.pandigital(1, 0), 1

    # length two
    assert_equal Euler.pandigital(2, 0), 12
    assert_equal Euler.pandigital(2, 1), 21

    # length three
    assert_equal Euler.pandigital(3, 0), 123
    assert_equal Euler.pandigital(3, 1), 132
    assert_equal Euler.pandigital(3, 2), 213
    assert_equal Euler.pandigital(3, 3), 231
    assert_equal Euler.pandigital(3, 4), 312
    assert_equal Euler.pandigital(3, 5), 321

    # length four
    assert_equal Euler.pandigital(5, 0), 12345
    assert_equal Euler.pandigital(5, 1), 12354
    assert_equal Euler.pandigital(5, 2), 12435
    assert_equal Euler.pandigital(5, 3), 12453
    assert_equal Euler.pandigital(5, 4), 12534
    assert_equal Euler.pandigital(5, 5), 12543
  end
end
