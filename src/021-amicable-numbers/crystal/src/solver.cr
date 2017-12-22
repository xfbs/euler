require "./divisor_sum"

module Solver
  def self.amicable_pair(num)
    partner = Euler.divisor_sum(num)

    if num != partner && num == Euler.divisor_sum(partner)
      partner
    else
      nil
    end
  end

  def self.solve(max)
    (1..max).map{|n| amicable_pair(n)}.compact.sum
  end
end
