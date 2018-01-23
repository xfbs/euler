module Solver
  def self.solve(n)
    factorial = factorial_trimmed n

    # take the number and compute the sum of it's digits
    factorial.to_s.chars.map(&:to_i).inject(:+)
  end

  def self.factorial_factorised(n)
    factors = {}
    (2..n).each do |f|
      factors.keys.each do |d|
        while (f % d) == 0
          f /= d
          factors[d] += 1
        end
      end

      factors[f] = 1 if f > 1
    end

    factors
  end

  def self.factorial_trimmed(n)
    factorised = factorial_factorised n

    if factorised[2] && factorised[5]
      # take out equal amounts of 2 and 5s (since their product is 10)
      while factorised[2] > 0 && factorised[5] > 0
        factorised[2] -= 1
        factorised[5] -= 1
      end
    end

    # this is not the actual factorial, but a version with the trailing zeroes
    # chopped off
    factorised.map { |f, e| f**e }.inject(:*)
  end
end
