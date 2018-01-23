module Solver
  def self.solve(n)
    (1..n).inject(1) { |c, m| c.lcm(m) }
  end
end
