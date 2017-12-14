require "big_int"

module Solver
  def self.solve(n)
    factorial = factorial_trimmed n

    # take the number and compute the sum of it's digits
    factorial.to_s.chars.map{|c| c.to_i}.sum
  end

  def self.factorial_factorised(n)
    factors = Hash(Int32, Int32).new
    (2..n).each do |f|
      factors.keys.each do |d|
        while (f%d) == 0
          f = f / d
          factors[d] += 1
        end
      end

      if f > 1
        factors[f] = 1
      end
    end

    factors
  end

  def self.factorial_trimmed(n)
    factorised = factorial_factorised n

    if factorised[2]? && factorised[5]?
      # take out equal amounts of 2 and 5s (since their product is 10)
      while factorised[2] > 0 && factorised[5] > 0
        factorised[2] -= 1
        factorised[5] -= 1
      end
    end

    # this is not the actual factorial, but a version with the trailing zeroes
    # chopped off
    factorised
      .map{|f, e| BigInt.new(f)**e}
      .reduce(BigInt.new(1)){|a, b| a*b}
  end
end
