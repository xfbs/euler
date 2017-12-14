require "./paths"

module Solver
  def self.solve(x, y)
    p = Paths.new(x, y)
    p.count(x, y)
  end
end
