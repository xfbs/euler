require "euler/sieve"

module Solver
  def self.solve(max)
    Euler::Sieve.new(max).sum
  end
end
