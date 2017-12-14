require "minitest/autorun"
require "../src/solver"

class SolverTest < Minitest::Test
  def setup
  end

  def test_solution
    assert_equal 22, Solver.solve([[11], [11, 10]])
    assert_equal 23, Solver.solve([[10], [12, 13]])
    assert_equal 65, Solver.solve([[10], [50, 9], [5, 4, 10]])
  end

  def test_reduce
    assert_equal [[22]], Solver.reduce([[11], [11, 10]])
    assert_equal [[23]], Solver.reduce([[10], [12, 13]])
    assert_equal [[10], [55, 19]], Solver.reduce([[10], [50, 9], [5, 4, 10]])
  end
end
