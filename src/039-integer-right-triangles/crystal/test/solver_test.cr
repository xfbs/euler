require "minitest/autorun"
require "../src/solver"

class SolverTest < Minitest::Test
  def test_number_of_solutions
    assert_equal 3, Solver.number_of_solutions(120)
  end
end
