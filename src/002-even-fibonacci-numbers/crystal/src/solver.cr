require "euler/fibonacci"

module Solver
  def self.solve(n)
    (1..n)
      .each
      .map { |i| Euler.fibonacci(3*i).to_u64 }
      .take_while { |i| i < n }
      .sum
  end
end
