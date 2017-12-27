require "euler/prime"

module Solver
  @@factorials = (0..9).map{|n| (1..n).reduce(1u64){|m, c| m*c}}.as(Array(UInt64))

  def self.solve(num)
    primes = Euler::Prime.new

    num.step(to: 1, by: -1).each do |n|
      @@factorials[n].step(to: 1, by: -1) do |nth|
        permutation = pandigital(n, nth-1)
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
      div=  primes.nth(cur)
    end

    true
  end

  def self.pandigital(n, nth)
    num = 0

    # this is a bitmap of which digits are taken
    taken = 0;

    while n > 0
      num *= 10

      # which of the remaining digits do we pick?
      choice = nth / @@factorials[n-1]
      nth %= @@factorials[n-1]

      # find the remaining digit
      digit = 0
      while choice != 0
          choice -= 1 unless (taken & (1 << digit)) > 0
          digit += 1
      end

      while (taken & (1 << digit)) > 0
          digit += 1
      end

      # mark this digit as used
      taken |= 1 << digit

      num += digit + 1
      n -= 1
    end

    num
  end
end

