require "./prime"

module Solver
  def self.solve(n)
    p = Prime.new
    p.nth(n-1)
  end
end
