#!/usr/bin/env ruby
require_relative 'solve'
require 'minitest'

class SolveTest < MiniTest::Test
  def setup
  end

  def test_check_pandigital
    assert_equal true, Solve.check_pandigital(123456789)
    assert_equal true, Solve.check_pandigital(234567891)
    assert_equal true, Solve.check_pandigital(345678912)
    assert_equal true, Solve.check_pandigital(456789123)
    assert_equal true, Solve.check_pandigital(123678945)

    assert_equal false, Solve.check_pandigital(1236789451)
    assert_equal false, Solve.check_pandigital(12367894)
    assert_equal false, Solve.check_pandigital(182678945)
    assert_equal false, Solve.check_pandigital(19)
    assert_equal false, Solve.check_pandigital(1023456789)
    assert_equal false, Solve.check_pandigital(1236789)
  end

  def test_check_pandigital_multiple
    assert_equal true, Solve.check_pandigital_multiple(192, 3)[0]
    assert_equal false, Solve.check_pandigital_multiple(191, 3)[0]
  end
end

MiniTest.autorun
