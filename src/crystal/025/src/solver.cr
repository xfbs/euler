module Solver
  PHI = (1 + Math.sqrt(5)) / 2

  def self.solve(max)
    (((1/2.0)*Math.log(5) + (max - 1)*Math.log(10)) / Math.log(PHI)).ceil.to_u32
  end
end
