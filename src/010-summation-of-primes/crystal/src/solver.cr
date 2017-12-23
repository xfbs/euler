require "./euler/prime_sieve"

module Solver
  def self.solve(n)
    Euler::PrimeSieve.new(n).map{|n| n.to_u64}.sum
  end
end
