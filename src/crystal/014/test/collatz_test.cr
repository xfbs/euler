require "minitest/autorun"
require "../src/collatz"

class PrimeTest < Minitest::Test
  def setup
  end

  def test_length
    c = Collatz.new

    assert_equal c.length(1_u32), 1
    assert_equal c.length(2_u32), 2
    assert_equal c.length(5_u32), 6
    assert_equal c.length(13_u32), 10
    assert_equal c.length(12_u32), 10
    assert_equal c.length(32_u32), 6
  end
end
