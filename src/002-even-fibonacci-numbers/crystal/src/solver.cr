require "./fibonacci"

module Solver
  def self.solve(n)
    (1..n)
      .each
      .map{|i| Fibonacci.nth(3*i).to_u64}
      .take_while{|i| i < n}
      .sum
  end
end
