require 'minitest/autorun'
require_relative '../src/solver'

class SolverTest < MiniTest::Test
  def test_solution
    assert_equal Solver.solve(['SKY']), 1
    assert_equal Solver.solve(%w[SKY HAMBURGER]), 1
    assert_equal Solver.solve(['HAMBURGER']), 0
  end
end
