require 'minitest/autorun'
require_relative '../src/solver'

class SolverTest < MiniTest::Test
  def test_p
    assert_equal Solver.p(1), 1
    assert_equal Solver.p(2), 5
    assert_equal Solver.p(3), 12
    assert_equal Solver.p(4), 22
    assert_equal Solver.p(5), 35
    assert_equal Solver.p(6), 51
  end

  def test_p_inverse
    assert_equal Solver.p_inverse(1), 1
    assert_equal Solver.p_inverse(5), 2
    assert_equal Solver.p_inverse(12), 3
    assert_equal Solver.p_inverse(22), 4
    assert_equal Solver.p_inverse(35), 5
    assert_equal Solver.p_inverse(51), 6
    assert_equal Solver.p_inverse(70), 7
  end

  def test_is_p
    assert Solver.is_p(1)
    assert Solver.is_p(5)
    assert Solver.is_p(12)
    assert Solver.is_p(22)
    assert Solver.is_p(35)
    assert Solver.is_p(51)
    assert Solver.is_p(70)

    assert !Solver.is_p(2)
    assert !Solver.is_p(3)
    assert !Solver.is_p(4)
    assert !Solver.is_p(6)
    assert !Solver.is_p(7)
    assert !Solver.is_p(8)
    assert !Solver.is_p(9)
    assert !Solver.is_p(10)
    assert !Solver.is_p(11)
    assert !Solver.is_p(13)
    assert !Solver.is_p(14)
    assert !Solver.is_p(15)
    assert !Solver.is_p(21)
    assert !Solver.is_p(23)
    assert !Solver.is_p(30)
    assert !Solver.is_p(50)
    assert !Solver.is_p(121)
  end

  def test_base
    assert_equal Solver.b(1), 4
    assert_equal Solver.b(2), 11
    assert_equal Solver.b(3), 21
    assert_equal Solver.b(4), 34
  end
end
