require "minitest/autorun"
require "../src/solver"

class SolverTest < Minitest::Test
  def test_solve
    assert_equal -126479, Solver.solve(1700)
  end

  def test_quadratic_prime_run
    p = Euler::Prime.new
    assert_equal 40, Solver.quadratic_prime_run(p, 1, 41)
    assert_equal 80, Solver.quadratic_prime_run(p, -79, 1601)
  end

  def test_prime_index
    p = Euler::Prime.new

    assert_nil p.index(4)
    assert_nil p.index(6)
    assert_nil p.index(8)
    assert_nil p.index(9)
    assert_nil p.index(10)
    assert_nil p.index(20)
    assert_nil p.index(100)
    assert_nil p.index(122)

    assert_equal p.index(2), 0
    assert_equal p.index(3), 1
    assert_equal p.index(5), 2
    assert_equal p.index(7), 3
    assert_equal p.index(13), 5
    assert_equal p.index(23), 8
    assert_equal p.index(31), 10
    assert_equal p.index(29), 9
  end
end
