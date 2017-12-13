#!/usr/bin/env ruby
require_relative 'solve'
require 'minitest'

class SolveTest < MiniTest::Test
  def setup
  end

  def test_num_to_digits
    assert_equal [1, 2, 3], Solve.num_to_digits_rev(123).reverse
    assert_equal [1, 7, 0, 9], Solve.num_to_digits_rev(1709).reverse
    assert_equal [1], Solve.num_to_digits_rev(1).reverse
    assert_equal [9, 9, 8, 9], Solve.num_to_digits_rev(9989).reverse
  end
end

MiniTest.autorun
