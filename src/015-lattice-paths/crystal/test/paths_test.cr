require "minitest/autorun"
require "../src/paths"

class PathTest < Minitest::Test
  def test_simple_paths
    p = Paths.new(10_u32, 10_u32)

    assert_equal p.count(0_u32, 0_u32), 1

    assert_equal p.count(4_u32, 0_u32), 1
    assert_equal p.count(2_u32, 0_u32), 1
    assert_equal p.count(9_u32, 0_u32), 1
    assert_equal p.count(3_u32, 0_u32), 1

    assert_equal p.count(4_u32, 1_u32), 5
    assert_equal p.count(1_u32, 1_u32), 2
    assert_equal p.count(8_u32, 1_u32), 9

    assert_equal p.count(1_u32, 4_u32), 5
    assert_equal p.count(1_u32, 8_u32), 9
    assert_equal p.count(1_u32, 2_u32), 3
    assert_equal p.count(1_u32, 6_u32), 7
  end

  def test_harder_paths
    p = Paths.new(10_u32, 10_u32)

    assert_equal p.count(2_u32, 2_u32), 6
    assert_equal p.count(2_u32, 3_u32), 10
    assert_equal p.count(3_u32, 2_u32), 10
    assert_equal p.count(5_u32, 3_u32), 56
    assert_equal p.count(4_u32, 4_u32), 70
    assert_equal p.count(3_u32, 4_u32), 35
  end

  def test_big_nums
    p = Paths.new(10_u32, 10_u32)

    assert_equal p.count(4_u32, 6_u32), 210
    assert_equal p.count(5_u32, 5_u32), 252
    assert_equal p.count(8_u32, 4_u32), 495
    assert_equal p.count(5_u32, 7_u32), 792

    big = Paths.new(20_u32, 20_u32)
    assert_equal big.count(20_u32, 16_u32), 7307872110
  end
end
