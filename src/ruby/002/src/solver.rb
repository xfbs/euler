require_relative 'fibonacci'

module Solver
  def self.solve(n)
    (1..n)
      .lazy
      .map { |i| Fibonacci.nth(3 * i) }
      .take_while { |i| i < n }
      .inject(0, :+)
  end
end
