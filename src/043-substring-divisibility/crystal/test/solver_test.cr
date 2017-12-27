require "minitest/autorun"
require "../src/solver"

class SolverTest < Minitest::Test
  def test_substring_divisible_step
    assert_equal Solver.substrdiv_step([] of Int32, [1, 2, 3]), [123]
    assert_equal Solver.substrdiv_step([] of Int32, [1, 2, 3, 4]), [1234]
    assert_equal Solver.substrdiv_step([3], [1, 2, 3, 4]), [1234, 61234, 91234]

    assert Solver.substrdiv_step([] of Int32,[1,4,0,6,3,5,7,2,8,9]).includes? 1406357289
    assert Solver.substrdiv_step([1], [4,0,6,3,5,7,2,8,9]).includes? 1406357289
    assert Solver.substrdiv_step([1,2], [0,6,3,5,7,2,8,9]).includes? 1406357289
    assert Solver.substrdiv_step([1,2,3], [6,3,5,7,2,8,9]).includes? 1406357289
    assert Solver.substrdiv_step([1,2,3,5], [3,5,7,2,8,9]).includes? 1406357289
    assert Solver.substrdiv_step([1,2,3,5,7], [5,7,2,8,9]).includes? 1406357289
    assert Solver.substrdiv_step([1,2,3,5,7,11], [7,2,8,9]).includes? 1406357289
    assert Solver.substrdiv_step([1,2,3,5,7,11,13], [2,8,9]).includes? 1406357289
  end

  def test_substring_divisible
    assert Solver.substrdiv([2,3,5,7,11,13,17]).includes? 1406357289
  end
end
