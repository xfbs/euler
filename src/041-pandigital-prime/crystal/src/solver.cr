require "euler/prime"
require "euler/pandigital"
require "euler/factorial"

module Solver
  def self.solve(num)
    primes = Euler::Prime.new

    num.step(to: 1, by: -1).each do |n|
      Euler.factorial64(n).step(to: 1, by: -1) do |nth|
        permutation = Euler.pandigital(n, nth - 1)
        if check?(primes, permutation)
          return permutation
        end
      end
    end

    0
  end

  def self.check?(primes, prime)
    root = Math.sqrt(prime).to_u64
    cur = 0
    div = primes.nth(cur)
    while div <= root
      if (prime % div) == 0
        return false
      end
      cur += 1
      div = primes.nth(cur)
    end

    true
  end
end
