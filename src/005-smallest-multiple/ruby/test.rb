#!/usr/bin/env ruby
require_relative 'solution'
require 'minitest'

class SolutionTest < MiniTest::Test
  def setup
  end

  def test_solution
    assert_equal Solution.solve(0), 1
    assert_equal Solution.solve(1), 1
    assert_equal Solution.solve(2), 2
    assert_equal Solution.solve(3), 6
    assert_equal Solution.solve(10), 2520
  end
end

MiniTest.autorun
