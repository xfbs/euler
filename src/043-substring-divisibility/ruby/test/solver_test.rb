require 'minitest/autorun'
require_relative '../src/solver'

class SolverTest < MiniTest::Test
  def test_substring_divisible_step
    assert_equal Solver.substrdiv_step([], [1, 2, 3]), [123]
    assert_equal Solver.substrdiv_step([], [1, 2, 3, 4]), [1234]
    assert_equal Solver.substrdiv_step([3], [1, 2, 3, 4]), [1234, 61234, 91234]

    assert Solver.substrdiv_step([],[1,4,0,6,3,5,7,2,8,9]).include? 1406357289
    assert Solver.substrdiv_step([1], [4,0,6,3,5,7,2,8,9]).include? 1406357289
    assert Solver.substrdiv_step([1,2], [0,6,3,5,7,2,8,9]).include? 1406357289
    assert Solver.substrdiv_step([1,2,3], [6,3,5,7,2,8,9]).include? 1406357289
    assert Solver.substrdiv_step([1,2,3,5], [3,5,7,2,8,9]).include? 1406357289
    assert Solver.substrdiv_step([1,2,3,5,7], [5,7,2,8,9]).include? 1406357289
    assert Solver.substrdiv_step([1,2,3,5,7,11], [7,2,8,9]).include? 1406357289
    assert Solver.substrdiv_step([1,2,3,5,7,11,13], [2,8,9]).include? 1406357289
  end

  def test_substring_divisible
    assert Solver.substrdiv([2,3,5,7,11,13,17]).include? 1406357289
  end
end
