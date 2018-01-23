require 'minitest/autorun'
require_relative '../src/solver'

class SolverTest < MiniTest::Test
  def test_solve
    # valid: product of empty sequence is 1
    assert_equal Solver.solve('', 0), 1
    assert_equal Solver.solve('1', 0), 1
    assert_equal Solver.solve('12', 0), 1
    assert_equal Solver.solve('123', 0), 1
    assert_equal Solver.solve('1232407128923', 0), 1
    assert_equal Solver.solve('000', 0), 1

    # invalid: string empty
    assert_equal Solver.solve('', 1), 0
    assert_equal Solver.solve('', 2), 0
    assert_equal Solver.solve('', 3), 0
    assert_equal Solver.solve('', 4), 0

    # invalid: string too short
    assert_equal Solver.solve('123', 4), 0
    assert_equal Solver.solve('123242', 10), 0
    assert_equal Solver.solve('1', 4), 0
    assert_equal Solver.solve('122341863', 12), 0

    # valid
    assert_equal Solver.solve('123', 3), 6
    assert_equal Solver.solve('123012340123', 4), 1 * 2 * 3 * 4
    assert_equal Solver.solve('097549087249983', 3), 9 * 9 * 8
    assert_equal Solver.solve('123456789', 7), 9 * 8 * 7 * 6 * 5 * 4 * 3

    # embedded zeroes
    assert_equal Solver.solve('99099099', 3), 0
    assert_equal Solver.solve('99099099', 3), 0
    assert_equal Solver.solve('990990990', 3), 0
    assert_equal Solver.solve('934191012', 7), 0
  end
end
