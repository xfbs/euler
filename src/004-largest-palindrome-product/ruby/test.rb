#!/usr/bin/env ruby
require 'minitest/autorun'
require_relative 'solve'

class SolveTest < MiniTest::Test
  def setup
  end

  def test_is_palindrome?
    assert Solve.is_palindrome?(101)
    assert Solve.is_palindrome?(163361)
    assert Solve.is_palindrome?(94249)
    assert Solve.is_palindrome?(3301033)
    assert Solve.is_palindrome?(19291)

    assert !Solve.is_palindrome?(19281)
    assert !Solve.is_palindrome?(123)
    assert !Solve.is_palindrome?(4923)
    assert !Solve.is_palindrome?(2439)
  end
end
