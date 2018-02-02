require_relative 'divisor_sum'

module Solver
  def self.amicable_pair(num)
    partner = Euler.divisor_sum(num)

    partner if num != partner && num == Euler.divisor_sum(partner)
  end

  def self.solve(max)
    (1..max).map { |n| amicable_pair(n) }.compact.inject(0, :+)
  end
end
