require "euler/prime"

module Solver
  def self.solve(max)
    product = 1_i32
    run = 0_u32
    prime = Euler::Prime.new

    ((-max + 1)...max).each do |a|
      (0..max).each do |b|
        break if prime.nth(b) >= max
        cur = quadratic_prime_run(prime, a, prime.nth(b))

        if cur > run
          run = cur
          product = a * prime.nth(b)
        end
      end
    end

    product
  end

  def self.quadratic_prime_run(primes, a : Int32, b : Int32) : UInt32
    n = 0_u32
    loop do
      cur = a*n + n*n + b
      break unless cur >= 2 && primes.index(cur)
      n += 1
    end

    n
  end
end
