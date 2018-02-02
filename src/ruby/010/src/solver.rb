require_relative './euler/sieve'

module Solver
  def self.solve(max)
    Euler::Sieve.new(max).inject(0, :+)
  end
end
