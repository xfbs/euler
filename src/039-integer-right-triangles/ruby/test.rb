#!/usr/bin/env ruby
require_relative 'solve'
require 'minitest'

class SolveTest < MiniTest::Test
  def setup
  end

  def test_number_of_solutions
    assert_equal 3, Solve.number_of_solutions(120)
  end
end

MiniTest.autorun
