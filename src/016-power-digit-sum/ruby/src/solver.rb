module Solver
  def self.solve n
    (2**n).to_s.chars.map{|c| c.to_i}.inject(:+)
  end
end
