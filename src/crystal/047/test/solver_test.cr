require "minitest/autorun"
require "../src/solver"

class SolverTest < Minitest::Test
  def test_distinct_prime_factors
    primes = Euler::Prime.new

    assert Solver.distinct_prime_factors(primes, 2, 14)
    assert Solver.distinct_prime_factors(primes, 3, 644)

    assert !Solver.distinct_prime_factors(primes, 2, 13)
    assert !Solver.distinct_prime_factors(primes, 2, 15)

    assert !Solver.distinct_prime_factors(primes, 3, 643)
    assert !Solver.distinct_prime_factors(primes, 3, 645)
  end

  def test_solve
    assert_equal Solver.solve(2), 14
    assert_equal Solver.solve(3), 644
  end
end
