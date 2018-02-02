module Solver
  def self.solve(max, a, b)
    sum_divisible(max, a) + sum_divisible(max, b) - sum_divisible(max, a.lcm(b))
  end

  def self.sum_divisible(max, div)
    max -= max % div
    max * ((max / div) + 1) / 2
  end
end
