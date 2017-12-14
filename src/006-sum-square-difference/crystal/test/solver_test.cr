require "minitest/autorun"
require "../src/solver"

class SolverTest < Minitest::Test
  def test_sum_of_squares
    assert_equal 1, Solver.sum_of_squares(1)
    assert_equal 5, Solver.sum_of_squares(2)
    assert_equal 14, Solver.sum_of_squares(3)
    assert_equal 30, Solver.sum_of_squares(4)
    assert_equal 55, Solver.sum_of_squares(5)
    assert_equal 385, Solver.sum_of_squares(10)
  end

  def test_square_of_sums
    assert_equal 1, Solver.square_of_sums(1)
    assert_equal 9, Solver.square_of_sums(2)
    assert_equal 36, Solver.square_of_sums(3)
    assert_equal 100, Solver.square_of_sums(4)
    assert_equal 225, Solver.square_of_sums(5)
    assert_equal 3025, Solver.square_of_sums(10)
  end

  def test_solution
    assert_equal 2640, Solver.solve(10)
  end
end
