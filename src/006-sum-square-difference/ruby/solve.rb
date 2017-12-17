module Solver
  def self.solve n
    (3 * n**4 + 2 * n**3 - 3 * n**2 - 2 * n) / 12
  end
end

if __FILE__ == $0
  puts Solver.solve(100)
end

