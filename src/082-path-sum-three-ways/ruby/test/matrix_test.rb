require 'test_helper'

class SolutionTest < MiniTest::Test
  SAMPLE_MATRIX = [
    [131, 673, 234, 103,  18],
    [201,  96, 342, 965, 150],
    [630, 803, 746, 422, 111],
    [537, 699, 497, 121, 956],
    [805, 732, 524,  37, 331]]

  def test_get_cell
    matrix = Solution::Matrix.new SAMPLE_MATRIX

    assert_equal matrix.get(0, 0).row, 0
    assert_equal matrix.get(0, 0).col, 0
    assert_equal matrix.get(1, 3).row, 1
    assert_equal matrix.get(1, 3).col, 3
    assert_equal matrix.get(0, 0).cell, 131
    assert_equal matrix.get(1, 0).cell, 201
    assert_equal matrix.get(0, 2).cell, 234
    assert_equal matrix.get(4, 4).cell, 331
  end

  def test_cell_movement
    matrix = Solution::Matrix.new SAMPLE_MATRIX

    assert_equal matrix.get(0, 0).right.row, 0
    assert_equal matrix.get(0, 0).right.col, 1
    assert_equal matrix.get(0, 0).down.row, 1
    assert_equal matrix.get(0, 0).down.col, 0
    assert_equal matrix.get(0, 0).up, nil
    assert_equal matrix.get(1, 0).up.row, 0
    assert_equal matrix.get(1, 0).up.col, 0
    assert_equal matrix.get(0, 0).right.cell, 673
    assert_equal matrix.get(1, 1).down.cell, 803
    assert_equal matrix.get(3, 4).down.cell, 331
    assert_equal matrix.get(4, 1).right.cell, 524
    assert_equal matrix.get(1, 1).up.cell, 673
  end

  def test_solve
    matrix = Solution::Matrix.new SAMPLE_MATRIX

    assert_equal matrix.get(4, 4).min_path, 331
    assert_equal matrix.get(0, 4).min_path, 18
    assert_equal matrix.get(0, 3).min_path, 121
    assert_equal matrix.get(4, 3).min_path, 368
    assert_equal matrix.get(3, 3).min_path, 489
    assert_equal matrix.get(0, 2).min_path, 355
    assert_equal matrix.get(3, 2).min_path, 986
    assert_equal matrix.get(1, 2).min_path, 697
    assert_equal matrix.get(1, 1).min_path, 793
    assert_equal matrix.get(1, 0).min_path, 994
  end
end
