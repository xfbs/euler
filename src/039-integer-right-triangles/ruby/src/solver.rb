require 'prime'

module Solver
  def self.solve max
    (1..max)
      .map{|p| [p, number_of_solutions(p)]}
      .sort_by{|p, n| n}
      .last
      .first
  end

  def self.number_of_solutions p
    (1..((p-3)/3))
      .count{|a| ((p * (2 * a - p)) % (2 * (a - p))) == 0}
  end
end
