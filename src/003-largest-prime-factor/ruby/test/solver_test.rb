require 'minitest/autorun'
require_relative '../src/solver'

class SolverTest < MiniTest::Test
  def test_is_prime
    assert Solver.is_prime?(2)
    assert Solver.is_prime?(3)
    assert Solver.is_prime?(5)
    assert Solver.is_prime?(7)
    assert Solver.is_prime?(11)
    assert Solver.is_prime?(13)

    assert !Solver.is_prime?(4)
    assert !Solver.is_prime?(6)
    assert !Solver.is_prime?(8)
    assert !Solver.is_prime?(15)
    assert !Solver.is_prime?(16)
    assert !Solver.is_prime?(21)
  end

  def test_solve
    assert_equal 2, Solver.solve(2)
    assert_equal 3, Solver.solve(6)
    assert_equal 5, Solver.solve(10)
  end
end
