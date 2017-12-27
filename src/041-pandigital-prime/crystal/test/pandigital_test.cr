require "minitest/autorun"
require "../src/euler/pandigital"

class PandigitalTest < Minitest::Test
  def test_pandigital
    assert_equal Euler.pandigital(5, 0), 12345
    assert_equal Euler.pandigital(5, 1), 12354
    assert_equal Euler.pandigital(5, 2), 12435
    assert_equal Euler.pandigital(5, 3), 12453
    assert_equal Euler.pandigital(5, 4), 12534
    assert_equal Euler.pandigital(5, 5), 12543
  end
end
