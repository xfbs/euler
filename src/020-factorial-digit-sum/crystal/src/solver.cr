require "big"

module Solver
  def self.solve(n)
    factorial = (1..n).reduce(BigInt.new(1)){|f, c| f * c}

    # take the number and compute the sum of it's digits
    factorial.to_s.chars.map{|c| c.to_i}.sum
  end
end
