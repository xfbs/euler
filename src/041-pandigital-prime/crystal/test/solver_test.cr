require "minitest/autorun"
require "../src/solver"

class SolverTest < Minitest::Test
  def test_solve
    assert_equal Solver.solve(4), 4231
  end

  def test_prime
    p = Euler::Prime.new
    assert Solver.check?(p, 2)
    assert Solver.check?(p, 3)
    assert Solver.check?(p, 5)
    assert Solver.check?(p, 7)
    assert Solver.check?(p, 11)
    assert Solver.check?(p, 13)
    assert Solver.check?(p, 17)
    assert Solver.check?(p, 19)

    assert !Solver.check?(p, 4)
    assert !Solver.check?(p, 6)
    assert !Solver.check?(p, 8)
    assert !Solver.check?(p, 9)
    assert !Solver.check?(p, 10)
    assert !Solver.check?(p, 15)
    assert !Solver.check?(p, 18)
    assert !Solver.check?(p, 21)
  end

  def test_pandigital
    assert_equal Solver.pandigital(5, 0), 12345
    assert_equal Solver.pandigital(5, 1), 12354
    assert_equal Solver.pandigital(5, 2), 12435
    assert_equal Solver.pandigital(5, 3), 12453
    assert_equal Solver.pandigital(5, 4), 12534
    assert_equal Solver.pandigital(5, 5), 12543
  end
end
