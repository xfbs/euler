require "euler/prime"

module Solver
  def self.solve(max)
    Euler::Prime.new
      .iter
      .take_while{|n| n < max}
      .map{|n| n.to_u64}
      .sum
  end
end
