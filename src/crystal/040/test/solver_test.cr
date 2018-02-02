require "minitest/autorun"
require "../src/solver"

class SolverTest < Minitest::Test
  def test_champernowne_digit
    (1..1000)
      .map { |n| n.to_s.split("").map { |n| n.to_i } }
      .flatten
      .each_with_index do |d, i|
      assert_equal d, Solver.champernowne_digit(i)
    end
  end
end
