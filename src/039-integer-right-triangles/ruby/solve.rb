#!/usr/bin/env ruby

module Solve
  def self.solve max
    (1..max).map do |p|
      [p, number_of_solutions(p)]
    end.sort_by{|p, n| n}.last.first
  end

  def self.number_of_solutions p
    (1..((p-3)/3)).map do |a|
      ((p * (2 * a - p)) % (2 * (a - p))) == 0
    end.count{|n| n}
  end
end

puts Solve.solve(1000).inspect
