#!/usr/bin/env ruby

module Solve
  def self.solve n
    (1..n).inject(1){|c, m| c.lcm(m)}
  end
end

puts Solve.solve(20) if __FILE__ == $0
