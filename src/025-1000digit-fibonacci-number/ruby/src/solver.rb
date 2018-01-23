module Solver
  PHI = (1 + Math.sqrt(5)) / 2

  def self.solve(max)
    ((0.5 * Math.log(5) + (max - 1) * Math.log(10)) / Math.log(PHI)).ceil
  end
end
