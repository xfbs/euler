require "minitest/autorun"
require "../src/solver"

class SolverTest < Minitest::Test
  def test_solver
    assert_equal Solver.solve(4, 0), 148748178147
  end

  def test_sequence
    p = Euler::Prime.new
    p.iter.take_while { |p| p < 10000 }

    assert Solver.test_sequence(p, 1487, 3330)
    assert Solver.test_sequence(p, 1487, 3300)
    assert !Solver.test_sequence(p, 1487, 3301)
  end

  def test_permutation
    assert Solver.is_permutations(1487, 3330)
    assert !Solver.is_permutations(1487, 1234)
  end
end
