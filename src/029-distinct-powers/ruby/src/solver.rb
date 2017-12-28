module Solver
  def self.solve max
    (2..max).map{|a| (2..max).map{|b| a**b}}.flatten.uniq.length
  end
end
