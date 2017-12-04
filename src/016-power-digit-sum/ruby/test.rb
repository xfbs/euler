#!/usr/bin/env ruby
require_relative 'solution'
require 'minitest'

class SolutionTest < MiniTest::Test
  def setup
  end

  def test_solution
    assert_equal 1, Solution.solve(0)
    assert_equal 2, Solution.solve(1)
    assert_equal 4, Solution.solve(2)
    assert_equal 8, Solution.solve(3)
    assert_equal 7, Solution.solve(4)
    assert_equal 5, Solution.solve(5)
    assert_equal 10, Solution.solve(6)
  end
end

MiniTest.autorun
