module Solver
  def self.solve(max)
    sum = 1
    cur = 1

    (2...max).step(2).each do |ring|
      cur += ring; sum += cur
      cur += ring; sum += cur
      cur += ring; sum += cur
      cur += ring; sum += cur
    end

    sum
  end
end
