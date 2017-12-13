#!/usr/bin/env ruby
require_relative 'solve'
require 'minitest'

class SolveTest < MiniTest::Test
  def setup
  end

  def test_is_prime
    assert Solve.is_prime?(2)
    assert Solve.is_prime?(3)
    assert Solve.is_prime?(5)
    assert Solve.is_prime?(7)
    assert Solve.is_prime?(11)
    assert Solve.is_prime?(13)

    assert !Solve.is_prime?(4)
    assert !Solve.is_prime?(6)
    assert !Solve.is_prime?(8)
    assert !Solve.is_prime?(15)
    assert !Solve.is_prime?(16)
    assert !Solve.is_prime?(21)
  end

  def test_solve
    assert_equal 2, Solve.solve(2)
    assert_equal 3, Solve.solve(6)
    assert_equal 5, Solve.solve(10)
  end
end

MiniTest.autorun
