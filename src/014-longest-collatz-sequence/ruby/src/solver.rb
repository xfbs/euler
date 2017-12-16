require_relative 'collatz'

module Solver
  def self.solve n
    c = Collatz.new(n)
    (1...n).map{|i| [c.length(i), i]}.max[1]
  end
end
