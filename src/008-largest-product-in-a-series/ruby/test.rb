#!/usr/bin/env ruby
require_relative 'solution'
require 'minitest'

class SolutionTest < MiniTest::Test
  def setup
  end

  def test_greatest_substring_product
    assert_equal 9, Solution.greatest_substring_product("123456789", 1)
    assert_equal 9, Solution.greatest_substring_product("923456780", 1)
    assert_equal 9, Solution.greatest_substring_product("123459780", 1)
    assert_equal 9, Solution.greatest_substring_product("123459780", 1)
    assert_equal 9, Solution.greatest_substring_product("023459780", 1)

    assert_equal 4, Solution.greatest_substring_product("304021", 1)
    assert_equal 0, Solution.greatest_substring_product("304021", 3)
    assert_equal 8, Solution.greatest_substring_product("304121", 3)

    assert_equal 720, Solution.greatest_substring_product("123454321", 5)
    assert_equal 720, Solution.greatest_substring_product("345432112", 5)
    assert_equal 720, Solution.greatest_substring_product("345432121", 5)
    assert_equal 720, Solution.greatest_substring_product("003454321", 5)
    assert_equal 720, Solution.greatest_substring_product("00345432100", 5)
    assert_equal 720, Solution.greatest_substring_product("00345342100", 5)
  end

  def test_solution
  end
end

MiniTest.autorun
