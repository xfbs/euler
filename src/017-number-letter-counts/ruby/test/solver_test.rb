require 'minitest/autorun'
require_relative '../src/solver'

class SolverTest < MiniTest::Test
  def setup
  end

  def test_solution
  end

  def test_teens_number_word
    assert_equal "one", Solver.teens_number_word(1)
    assert_equal "five", Solver.teens_number_word(5)
    assert_equal "seven", Solver.teens_number_word(7)
    assert_equal "thirteen", Solver.teens_number_word(13)
    assert_equal "twenty", Solver.teens_number_word(20)
    assert_equal "twenty-one", Solver.teens_number_word(21)
    assert_equal "forty-five", Solver.teens_number_word(45)
    assert_equal "ninety-eight", Solver.teens_number_word(98)
    assert_equal "seventy", Solver.teens_number_word(70)
    assert_equal "thirty-three", Solver.teens_number_word(33)
  end

  def test_hundreds_number_word
    assert_equal "fifty-five", Solver.hundreds_number_word(55)
    assert_equal "one hundred", Solver.hundreds_number_word(100)
    assert_equal "one hundred and fifty-five", Solver.hundreds_number_word(155)
    assert_equal "seven hundred and five", Solver.hundreds_number_word(705)
  end
end
