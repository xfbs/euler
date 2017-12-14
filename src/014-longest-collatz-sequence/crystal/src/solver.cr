require "./collatz"

module Solver
  def self.solve(n : UInt32)
    c = Collatz.new(n)
    (1_u32...n).map{|i| [c.length(i), i]}.max[1]
  end
end
