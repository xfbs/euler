require "big_int"

module Solver
  def self.solve(max)
    (2..max)
      .map{|a| (2..max).map{|b| BigInt.new(a)**b}}
      .flatten
      .uniq
      .size
  end
end
