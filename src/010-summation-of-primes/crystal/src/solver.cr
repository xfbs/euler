require "euler/prime"

module Solver
  def self.solve(max)
    sum = 0_u64
    pos = 0
    p = Euler::Prime.new

    while p.nth(pos) < max
      sum += p.nth(pos)
      pos += 1
    end

    sum
  end
end
