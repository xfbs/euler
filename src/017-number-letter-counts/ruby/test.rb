#!/usr/bin/env ruby
require_relative 'solution'
require 'minitest'

class SolutionTest < MiniTest::Test
  def setup
  end

  def test_solution
  end

  def test_teens_number_word
    assert_equal "one", Solution.teens_number_word(1)
    assert_equal "five", Solution.teens_number_word(5)
    assert_equal "seven", Solution.teens_number_word(7)
    assert_equal "thirteen", Solution.teens_number_word(13)
    assert_equal "twenty", Solution.teens_number_word(20)
    assert_equal "twenty-one", Solution.teens_number_word(21)
    assert_equal "forty-five", Solution.teens_number_word(45)
    assert_equal "ninety-eight", Solution.teens_number_word(98)
    assert_equal "seventy", Solution.teens_number_word(70)
    assert_equal "thirty-three", Solution.teens_number_word(33)
  end

  def test_hundreds_number_word
    assert_equal "fifty-five", Solution.hundreds_number_word(55)
    assert_equal "one hundred", Solution.hundreds_number_word(100)
    assert_equal "one hundred and fifty-five", Solution.hundreds_number_word(155)
    assert_equal "seven hundred and five", Solution.hundreds_number_word(705)
  end
end

MiniTest.autorun
