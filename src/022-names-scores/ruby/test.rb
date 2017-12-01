#!/usr/bin/env ruby
require_relative 'solution'
require 'minitest'

class SolutionTest < MiniTest::Test
  def setup
  end

  def test_weight
    assert_equal 1, Solution.weight("A")
    assert_equal 26, Solution.weight("Z")
    assert_equal 53, Solution.weight("COLIN")
  end
end

MiniTest.autorun
