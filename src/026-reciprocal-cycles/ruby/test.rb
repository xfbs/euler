#!/usr/bin/env ruby
require_relative 'solution'
require 'minitest'

class SolutionTest < MiniTest::Test
  def setup
  end

  def test_solve
    assert_equal 7, Solution.solve(10)
    assert_equal 3, Solution.solve(4)
  end

  def test_reciprocal_cycle
    assert_equal 0, Solution.reciprocal_cycle(2)
    assert_equal 1, Solution.reciprocal_cycle(3)
    assert_equal 6, Solution.reciprocal_cycle(7)
  end
end

MiniTest.autorun
