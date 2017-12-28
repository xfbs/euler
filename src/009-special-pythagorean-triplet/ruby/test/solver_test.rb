require 'minitest/autorun'
require_relative '../src/solver'

class SolverTest < MiniTest::Test
  def test_solution
    assert_equal 60, Solver.solve(12)
  end

  def test_is_pythagorean_triplet?
    assert Solver.is_pythagorean_triplet?(3, 4, 5)
    assert !Solver.is_pythagorean_triplet?(4, 3, 5)
    assert !Solver.is_pythagorean_triplet?(3, 4, 6)
  end
end
