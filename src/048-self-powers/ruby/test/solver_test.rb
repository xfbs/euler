require 'minitest/autorun'
require_relative '../src/solver'

class SolverTest < MiniTest::Test
  def test_solver
    assert_equal Solver.solve(5, 10), 1**1 + 2**2 + 3**3 + 4**4 + 5**5
    assert_equal Solver.solve(5, 3), (1**1 + 2**2 + 3**3 + 4**4 + 5**5) % 1000
    assert_equal Solver.solve(5, 2), (1**1 + 2**2 + 3**3 + 4**4 + 5**5) % 100
    assert_equal Solver.solve(5, 1), (1**1 + 2**2 + 3**3 + 4**4 + 5**5) % 10
  end

  def test_pow
    [123, 1000, 24_312, 2_003_232].each do |m|
      (1..1000).each do |n|
        assert_equal Solver.pow(n, n, m), n**n % m
      end
    end
  end
end
