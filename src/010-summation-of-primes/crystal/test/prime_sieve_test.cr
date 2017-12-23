require "minitest/autorun"
require "../src/euler/prime_sieve"

class PrimeSieveTest < Minitest::Test
  def setup
  end

  def test_sieve_small
    p = Euler::PrimeSieve.new(20)
    e = p.to_a

    assert_equal e[0], 2
    assert_equal e[1], 3
    assert_equal e[2], 5
    assert_equal e[3], 7
    assert_equal e[4], 11
    assert_equal e[5], 13
    assert_equal e[6], 17
    assert_equal e[7], 19
    assert_nil e[8]?, nil
  end

  def test_sieve_med
    p = Euler::PrimeSieve.new(100)
    e = p.to_a

    assert_equal e, [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53,
                     59, 61, 67, 71, 73, 79, 83, 89, 97]
  end
end
