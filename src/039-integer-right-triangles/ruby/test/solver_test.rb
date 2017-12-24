require 'minitest/autorun'
require_relative '../src/solver'

class SolverTest < MiniTest::Test
  def setup
  end

  def test_number_of_solutions
    assert_equal 3, Solver.number_of_solutions(120)
  end
end
