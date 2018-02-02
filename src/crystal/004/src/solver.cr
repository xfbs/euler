require "euler/math"

module Solver
  def self.solve(digits)
    min = 10**(digits - 1)
    max = 10**digits
    (min...max).map do |a|
      (a...max).select do |b|
        Euler.is_palindrome?(a * b)
      end.map do |b|
        a * b
      end.max? || 0
    end.max
  end
end
