require "euler/prime"

module Solver
  def self.solve(max)
    Euler::Prime.new
      .iter
      .take_while{|n| n < max}
      .sum
  end
end
