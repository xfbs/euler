#!/usr/bin/env ruby
require_relative 'solution'
require 'minitest'

class SolutionTest < MiniTest::Test
  def setup
  end

  def test_solution
    assert_equal 2763600, Solution.solve([
      [17, 20, 5, 12],
      [99, 9, 98, 2],
      [7, 25, 12, 88],
      [94, 21, 0, 41]])

    assert_equal 3884832, Solution.solve([
      [17, 20, 5, 12],
      [99, 9, 98, 2],
      [7, 25, 12, 88],
      [94, 21, 48, 41]])
  end

  def test_quadruple_products
    assert_equal [], Solution.quadruple_products([], 0, 0)
    assert_equal [[1]], Solution.quadruple_products([[1]], 0, 0)
  end

  def test_quadruple_products_horizontal
    assert_equal [[1,2,4,8]], Solution.quadruple_products([[1,1,1,1,2,2,2]],1,0)
  end

  def test_quadruple_products_vertical
    assert_equal [[1],[2],[4],[8]],
      Solution.quadruple_products([[1],[1],[1],[1],[2],[2],[2]],0,1)
  end

  def test_quadruple_products_diagonal
    assert_equal [[1, 2],[4, 8]],
      Solution.quadruple_products([
        [1, 1, 1, 1, 1],
        [1, 1, 1, 1, 1],
        [1, 1, 1, 1, 1],
        [1, 1, 2, 1, 2],
        [1, 1, 1, 2, 8]
    ],1,1)
  end

  def test_quadruple_products_diagonal_inverted
    assert_equal [[6]],
      Solution.quadruple_products([
        [0, 0, 0, 1],
        [0, 0, 2, 0],
        [0, 1, 0, 0],
        [3, 0, 0, 0]
    ],-1,1)

    assert_equal [[6, 105], [105, 0]],
      Solution.quadruple_products([
        [0, 0, 0, 1, 3],
        [0, 0, 2, 7, 1],
        [0, 1, 5, 0, 0],
        [3, 1, 0, 0, 9],
        [3, 0, 0, 0, 4]
    ],-1,1)
  end
end

MiniTest.autorun
