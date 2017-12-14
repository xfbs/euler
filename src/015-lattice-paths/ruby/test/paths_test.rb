require 'minitest/autorun'
require_relative '../src/paths'

class PathsTest < MiniTest::Test
  def setup
    @p = Paths.new(10, 10)
  end

  def test_simple_paths
    assert_equal @p.count(0, 0), 1

    assert_equal @p.count(4, 0), 1
    assert_equal @p.count(2, 0), 1
    assert_equal @p.count(9, 0), 1
    assert_equal @p.count(3, 0), 1

    assert_equal @p.count(4, 1), 5
    assert_equal @p.count(1, 1), 2
    assert_equal @p.count(8, 1), 9

    assert_equal @p.count(1, 4), 5
    assert_equal @p.count(1, 8), 9
    assert_equal @p.count(1, 2), 3
    assert_equal @p.count(1, 6), 7
  end

  def test_harder_paths
    assert_equal @p.count(2, 2), 6
    assert_equal @p.count(2, 3), 10
    assert_equal @p.count(3, 2), 10
    assert_equal @p.count(5, 3), 56
    assert_equal @p.count(4, 4), 70
    assert_equal @p.count(3, 4), 35
  end

  def test_big_nums
    assert_equal @p.count(4, 6), 210
    assert_equal @p.count(5, 5), 252
    assert_equal @p.count(8, 4), 495
    assert_equal @p.count(5, 7), 792

    big = Paths.new(20, 20)
    assert_equal big.count(20, 16), 7307872110
  end
end
