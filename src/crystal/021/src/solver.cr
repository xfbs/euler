require "euler/divisors"

module Solver
  def self.amicable_pair(num)
    partner = Euler.divisors(num).sum

    if num != partner && num == Euler.divisors(partner).sum
      partner
    else
      nil
    end
  end

  def self.solve(max)
    (1..max).map { |n| amicable_pair(n) }.compact.sum
  end
end
