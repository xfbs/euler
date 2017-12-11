#!/usr/bin/env ruby
require_relative 'solve'
require 'minitest'

class SolveTest < MiniTest::Test
  def setup
  end

  def test_solution
    assert_equal Solve.solve(["SKY"]), 1
    assert_equal Solve.solve(["SKY", "HAMBURGER"]), 1
    assert_equal Solve.solve(["HAMBURGER"]), 0
  end
end

MiniTest.autorun
