#!/usr/bin/env ruby
require 'minitest/autorun'
require_relative 'solve'

class SolverTest < MiniTest::Test
  def setup
  end

  def test_solution
    assert_equal 2640, Solver.solve(10)
  end
end
