#!/usr/bin/env ruby
require_relative 'solution'
require 'minitest'

class SolutionTest < MiniTest::Test
  def setup
  end

  def test_solution
    assert_equal 60, Solution.solve(12)
  end

  def test_is_pythagorean_triplet?
    assert Solution.is_pythagorean_triplet?(3, 4, 5)
    assert !Solution.is_pythagorean_triplet?(4, 3, 5)
    assert !Solution.is_pythagorean_triplet?(3, 4, 6)
  end
end

MiniTest.autorun
