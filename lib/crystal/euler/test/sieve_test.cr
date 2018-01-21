require "minitest/autorun"
require "../src/euler/sieve"

class SieveTest < Minitest::Test
  def test_sieve_small
    assert_equal Euler::Sieve.new(10).to_a, [2, 3, 5, 7]
    assert_equal Euler::Sieve.new(15).to_a, [2, 3, 5, 7, 11, 13]
    assert_equal Euler::Sieve.new(25).to_a, [2, 3, 5, 7, 11, 13, 17, 19, 23]
  end

  def test_sieve_large
    assert_equal Euler::Sieve.new(100).size, 25
    assert_equal Euler::Sieve.new(1000).size, 168
    assert_equal Euler::Sieve.new(10000).size, 1229
  end
end
