#!/usr/bin/env ruby
require_relative 'solution'
require 'minitest'

class SolutionTest < MiniTest::Test
  def setup
  end

  def test_solve
    assert_equal true, Solution.check_fraction(4, 9, 9, 8)
    assert_equal false, Solution.check_fraction(3, 0, 5, 0)
  end
end

MiniTest.autorun
