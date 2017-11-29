#!/usr/bin/env ruby
require_relative 'solution'
require 'minitest'

class SolutionTest < MiniTest::Test
  def setup
  end

  def test_sum_of_squares
    assert_equal 1, Solution.sum_of_squares(1)
    assert_equal 5, Solution.sum_of_squares(2)
    assert_equal 14, Solution.sum_of_squares(3)
    assert_equal 30, Solution.sum_of_squares(4)
    assert_equal 55, Solution.sum_of_squares(5)
    assert_equal 385, Solution.sum_of_squares(10)
  end

  def test_square_of_sums
    assert_equal 1, Solution.square_of_sums(1)
    assert_equal 9, Solution.square_of_sums(2)
    assert_equal 36, Solution.square_of_sums(3)
    assert_equal 100, Solution.square_of_sums(4)
    assert_equal 225, Solution.square_of_sums(5)
    assert_equal 3025, Solution.square_of_sums(10)
  end

  def test_solution
    assert_equal 2640, Solution.solve(10)
  end
end

MiniTest.autorun
