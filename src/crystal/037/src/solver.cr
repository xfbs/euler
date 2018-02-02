require "euler/prime"

module Solver
  def self.solve(num)
    sum = 0
    primes = Euler::Prime.new
    primes
      .iter
      .skip_while { |p| p < 10 }
      .select { |p| is_truncatable_prime?(primes, p) }
      .first(num)
      .sum
  end

  def self.is_truncatable_prime?(primes, p)
    cur = p / 10
    exp = 10
    while cur > 0
      unless primes.index(cur)
        return false
      end
      unless primes.index(p % exp)
        return false
      end
      cur /= 10
      exp *= 10
    end

    true
  end
end
