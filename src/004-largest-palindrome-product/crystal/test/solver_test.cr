require "minitest/autorun"
require "../src/solver"

class SolverTest < Minitest::Test
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
end
