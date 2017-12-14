require "big_int"

module Solver
  def self.solve(n)
    (BigInt.new(2).to_big_i**n).to_s.chars.map{|c| c.to_i}.sum
  end
end
