require "minitest/autorun"
require "../src/solver"

class SolverTest < Minitest::Test
  def test_solve
    s = Date.new(Date::FRIDAY, 1, Date::JANUARY, 2016)
    e = Date.new(Date::THURSDAY, 1, Date::JANUARY, 2017)
    assert_equal Solver.solve(s, e), 1
  end
end
