require 'minitest/autorun'
require_relative '../src/solver'

class SolverTest < MiniTest::Test
  def test_is_palindrome?
    assert Solver.is_palindrome?(101)
    assert Solver.is_palindrome?(163361)
    assert Solver.is_palindrome?(94249)
    assert Solver.is_palindrome?(3301033)
    assert Solver.is_palindrome?(19291)

    assert !Solver.is_palindrome?(19281)
    assert !Solver.is_palindrome?(123)
    assert !Solver.is_palindrome?(4923)
    assert !Solver.is_palindrome?(2439)
  end

  def test_solve
    assert_equal Solver.solve(2), 9009
  end
end
