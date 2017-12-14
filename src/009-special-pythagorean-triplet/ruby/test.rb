#!/usr/bin/env ruby
require 'minitest/autorun'
require_relative 'solve'

class SolverTest < MiniTest::Test
  def setup
  end

  def test_solution
    assert_equal 60, Solver.solve(12)
  end

  def test_is_pythagorean_triplet?
    assert Solver.is_pythagorean_triplet?(3, 4, 5)
    assert !Solver.is_pythagorean_triplet?(4, 3, 5)
    assert !Solver.is_pythagorean_triplet?(3, 4, 6)
  end
end
