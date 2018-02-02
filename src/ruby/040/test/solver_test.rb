require 'minitest/autorun'
require_relative '../src/solver'

class SolverTest < MiniTest::Test
  def test_champernowne_digit
    (1..1000)
      .map { |n| n.to_s.split('').map(&:to_i) }
      .flatten
      .each_with_index do |d, i|
      assert_equal d, Solver.champernowne_digit(i)
    end
  end
end
