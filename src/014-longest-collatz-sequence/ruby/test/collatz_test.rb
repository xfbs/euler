require 'minitest/autorun'
require_relative '../src/collatz'

class PrimeTest < MiniTest::Test
  def setup; end

  def test_length
    c = Collatz.new

    assert_equal c.length(1), 1
    assert_equal c.length(2), 2
    assert_equal c.length(5), 6
    assert_equal c.length(13), 10
    assert_equal c.length(12), 10
    assert_equal c.length(32), 6
  end
end
