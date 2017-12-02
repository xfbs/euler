#!/usr/bin/env ruby
require_relative 'solution'
require 'minitest'

class SolutionTest < MiniTest::Test
  def setup
  end

  def test_solution
    assert_equal Solution.solve(5), 15
  end
end

MiniTest.autorun
