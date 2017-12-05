#!/usr/bin/env ruby
require_relative 'solve'
require 'minitest'

class SolveTest < MiniTest::Test
  def setup
  end

  def test_solution
    assert_equal Solve.solve(0), 1
    assert_equal Solve.solve(1), 1
    assert_equal Solve.solve(2), 2
    assert_equal Solve.solve(3), 6
    assert_equal Solve.solve(10), 2520
  end
end

MiniTest.autorun
