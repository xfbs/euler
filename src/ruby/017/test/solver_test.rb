require 'minitest/autorun'
require_relative '../src/solver'

class SolverTest < MiniTest::Test
  def test_teens_number_word
    assert_equal  3, Solver.teens_number_word(1)  # one
    assert_equal  4, Solver.teens_number_word(5)  # four
    assert_equal  5, Solver.teens_number_word(7)  # seven
    assert_equal  8, Solver.teens_number_word(13) # thirteen
    assert_equal  6, Solver.teens_number_word(20) # twenty
    assert_equal  9, Solver.teens_number_word(21) # twenty-one
    assert_equal  9, Solver.teens_number_word(45) # forty-five
    assert_equal 11, Solver.teens_number_word(98) # ninety-eight
    assert_equal 7, Solver.teens_number_word(70) # seventy
    assert_equal 11, Solver.teens_number_word(33) # thirty-three
  end

  def test_hundreds_number_word
    # fifty-five
    assert_equal 9, Solver.hundreds_number_word(55)

    # one-hundred
    assert_equal 10, Solver.hundreds_number_word(100)

    # one hundred and fifty-five
    assert_equal 22, Solver.hundreds_number_word(155)

    # seven hundred and five
    assert_equal 19, Solver.hundreds_number_word(705)

    # nine hundred and ninety-four
    assert_equal 24, Solver.hundreds_number_word(994)
  end

  def test_thousands_number_word
    # one thousand
    assert_equal 11, Solver.thousands_number_word(1000)

    # one thousand, seven hundred and sixty-four
    assert_equal 35, Solver.thousands_number_word(1764)
  end

  def test_solve
    # one
    assert_equal 3, Solver.solve(1)

    # one two three four five six seven eight nine ten
    assert_equal 39, Solver.solve(10)
  end
end
