require 'minitest/autorun'
require_relative '../src/solver'

class SolverTest < MiniTest::Test
  def test_is_palindrome_base_10
    assert Solver.is_palindrome?(121)
    assert Solver.is_palindrome?(1_234_321)
    assert Solver.is_palindrome?(1221)
    assert Solver.is_palindrome?(12_345_054_321)
    assert Solver.is_palindrome?(1_664_661)

    assert !Solver.is_palindrome?(112)
    assert !Solver.is_palindrome?(55_554_555)
    assert !Solver.is_palindrome?(1121)
    assert !Solver.is_palindrome?(1612)
    assert !Solver.is_palindrome?(9_999_991)
  end

  def test_is_palindrome_base_2
    assert Solver.is_palindrome?(0b1001, 2)
    assert Solver.is_palindrome?(0b110010011, 2)
    assert Solver.is_palindrome?(0b1100110011, 2)
    assert Solver.is_palindrome?(0b10101, 2)
    assert Solver.is_palindrome?(0b101, 2)

    assert !Solver.is_palindrome?(0b1010, 2)
    assert !Solver.is_palindrome?(0b101010, 2)
    assert !Solver.is_palindrome?(0b100101, 2)
    assert !Solver.is_palindrome?(0b10111010, 2)
    assert !Solver.is_palindrome?(0b101011, 2)
  end

  def test_gen_palindromes
    assert_equal Solver.gen_palindromes(12), [121, 1221]
    assert_equal Solver.gen_palindromes(131), [13_131, 131_131]

    assert_equal Solver.gen_palindromes(0b10, 2), [0b101, 0b1001]
    assert_equal Solver.gen_palindromes(0b1011, 2), [0b1011101, 0b10111101]
  end
end
