module Solver
  def self.solve(n)
    (1..n).reduce(1_u64) { |c, m| c.lcm(m) }
  end
end
