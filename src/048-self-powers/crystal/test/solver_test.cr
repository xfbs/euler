require "minitest/autorun"
require "../src/solver"

class SolverTest < Minitest::Test
  def test_solver
    assert_equal Solver.solve(5, 10), 1**1+2**2+3**3+4**4+5**5
    assert_equal Solver.solve(5, 3), (1**1+2**2+3**3+4**4+5**5)%1000
    assert_equal Solver.solve(5, 2), (1**1+2**2+3**3+4**4+5**5)%100
    assert_equal Solver.solve(5, 1), (1**1+2**2+3**3+4**4+5**5)%10
  end
end
