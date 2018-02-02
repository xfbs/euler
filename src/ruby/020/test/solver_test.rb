require 'minitest/autorun'
require_relative '../src/solver'

class SolverTest < MiniTest::Test
  def test_factorial_factorised
    assert_equal Solver.factorial_factorised(2), 2 => 1
    assert_equal Solver.factorial_factorised(3), 2 => 1, 3 => 1
    assert_equal Solver.factorial_factorised(4), 2 => 3, 3 => 1
    assert_equal Solver.factorial_factorised(5), 2 => 3, 3 => 1, 5 => 1
    assert_equal Solver.factorial_factorised(6), 2 => 4, 3 => 2, 5 => 1
  end

  def test_factorial_trimmed
    assert_equal Solver.factorial_trimmed(2), 2
    assert_equal Solver.factorial_trimmed(3), 6
    assert_equal Solver.factorial_trimmed(4), 24
    assert_equal Solver.factorial_trimmed(10), 36_288
  end

  def test_solution
    assert_equal Solver.solve(10), 27
  end
end
