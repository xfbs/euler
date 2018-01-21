require "minitest/autorun"
require "../src/euler/prime"

class PrimeTest < Minitest::Test
  def test_nth
    p = Euler::Prime.new

    assert_equal p.nth(0), 2
    assert_equal p.nth(1), 3
    assert_equal p.nth(2), 5
    assert_equal p.nth(3), 7
    assert_equal p.nth(4), 11
    assert_equal p.nth(5), 13
    assert_equal p.nth(6), 17
    assert_equal p.nth(7), 19
  end

  def test_next
    p = Euler::Prime.new

    assert_equal p.next, 5
    assert_equal p.next, 7
    assert_equal p.next, 11
    assert_equal p.next, 13
    assert_equal p.next, 17
    assert_equal p.next, 19
    assert_equal p.next, 23
  end

  def test_iter
    p = Euler::Prime.new

    assert_equal p.iter().first(5).to_a, [2, 3, 5, 7, 11]
    assert_equal p.iter().first(2).to_a, [2, 3]
    assert_equal p.iter().first(8).to_a, [2, 3, 5, 7, 11, 13, 17, 19]
  end

  def test_check
    p = Euler::Prime.new

    assert_equal p.check?(2), true
    assert_equal p.check?(3), true
    assert_equal p.check?(4), false
    assert_equal p.check?(5), true
    assert_equal p.check?(6), false
    assert_equal p.check?(7), true
    assert_equal p.check?(8), false
    assert_equal p.check?(9), false
    assert_equal p.check_fast?(25), false
  end

  def test_index
    p = Euler::Prime.new

    assert_equal p.index(0), nil
    assert_equal p.index(1), nil
    assert_equal p.index(2), 0
    assert_equal p.index(3), 1
    assert_equal p.index(4), nil
    assert_equal p.index(5), 2
    assert_equal p.index(6), nil
    assert_equal p.index(7), 3
    assert_equal p.index(8), nil
    assert_equal p.index(9), nil
    assert_equal p.index(11), 4
    assert_equal p.index(13), 5
    assert_equal p.index(17), 6
  end
end
