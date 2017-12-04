#!/usr/bin/env ruby
require_relative 'solution'
require 'minitest'

class SolutionTest < MiniTest::Test
  def setup
  end

  def test_solution
    assert_equal 22, Solution.solve([[11], [11, 10]])
    assert_equal 23, Solution.solve([[10], [12, 13]])
    assert_equal 65, Solution.solve([[10], [50, 9], [5, 4, 10]])
  end

  def test_reduce
    assert_equal [[22]], Solution.reduce([[11], [11, 10]])
    assert_equal [[23]], Solution.reduce([[10], [12, 13]])
    assert_equal [[10], [55, 19]], Solution.reduce([[10], [50, 9], [5, 4, 10]])
  end
end

MiniTest.autorun
