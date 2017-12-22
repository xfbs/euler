require "./sieve"

module Solver
  def self.solve(n)
    Sieve.new(n).map{|n| n.to_u64}.sum
  end
end
