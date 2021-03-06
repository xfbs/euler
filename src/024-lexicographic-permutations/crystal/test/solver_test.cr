require "minitest/autorun"
require "../src/solver"

class SolverTest < Minitest::Test
  def test_solve
    assert_equal "123", Solver.solve([1, 2, 3], 0)
    assert_equal "321", Solver.solve([1, 2, 3], 5)
  end

  def test_permutation
    assert_equal [1, 2, 3], Solver.permutation([1, 2, 3], 0)
    assert_equal [1, 3, 2], Solver.permutation([1, 2, 3], 1)
    assert_equal [2, 1, 3], Solver.permutation([1, 2, 3], 2)
    assert_equal [2, 3, 1], Solver.permutation([1, 2, 3], 3)
    assert_equal [3, 1, 2], Solver.permutation([1, 2, 3], 4)
    assert_equal [3, 2, 1], Solver.permutation([1, 2, 3], 5)
  end
end
