require "minitest/autorun"
require "../src/solver"

class SolverTest < Minitest::Test
  def test_solve
    assert_equal 2763600, Solver.solve([
      [17, 20, 5, 12],
      [99, 9, 98, 2],
      [7, 25, 12, 88],
      [94, 21, 0, 41],
    ])

    assert_equal 3884832, Solver.solve([
      [17, 20, 5, 12],
      [99, 9, 98, 2],
      [7, 25, 12, 88],
      [94, 21, 48, 41],
    ])
  end

  def test_quadruple_products
    assert_equal [] of Int32, Solver.quadruple_products([] of Array(Int32), 0, 0)
    assert_equal [[1]], Solver.quadruple_products([[1]], 0, 0)
  end

  def test_quadruple_products_horizontal
    assert_equal [[1, 2, 4, 8]], Solver.quadruple_products([[1, 1, 1, 1, 2, 2, 2]], 1, 0)
  end

  def test_quadruple_products_vertical
    assert_equal [[1], [2], [4], [8]],
      Solver.quadruple_products([[1], [1], [1], [1], [2], [2], [2]], 0, 1)
  end

  def test_quadruple_products_diagonal
    assert_equal [[1, 2], [4, 8]],
      Solver.quadruple_products([
        [1, 1, 1, 1, 1],
        [1, 1, 1, 1, 1],
        [1, 1, 1, 1, 1],
        [1, 1, 2, 1, 2],
        [1, 1, 1, 2, 8],
      ], 1, 1)
  end

  def test_quadruple_products_diagonal_inverted
    assert_equal [[6]],
      Solver.quadruple_products([
        [0, 0, 0, 1],
        [0, 0, 2, 0],
        [0, 1, 0, 0],
        [3, 0, 0, 0],
      ], -1, 1)

    assert_equal [[6, 105], [105, 0]],
      Solver.quadruple_products([
        [0, 0, 0, 1, 3],
        [0, 0, 2, 7, 1],
        [0, 1, 5, 0, 0],
        [3, 1, 0, 0, 9],
        [3, 0, 0, 0, 4],
      ], -1, 1)
  end
end
