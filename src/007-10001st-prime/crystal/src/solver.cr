require "euler/prime"

module Solver
  def self.solve(n)
    p = Euler::Prime.new
    p.nth(n-1)
  end
end
