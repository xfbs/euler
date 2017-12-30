require 'euler/prime'

module Solver
  def self.solve max
    triangle = 1
    index = 1
    p = Euler::Prime.new

    while factor_count(p, triangle) <= max
      index += 1
      triangle += index
    end

    triangle
  end

  def self.factor_count primes, num
    count = 1
    cur = 0

    while num != 1
      factors = 1
      prime = primes.nth(cur)

      while (num % prime) == 0
        num /= prime
        factors += 1
      end


      count *= factors
      cur += 1
    end

    count
  end
end
