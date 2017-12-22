module Solver
  def self.divisor_sum(num)
    (1..Math.sqrt(num)).map do |d|
      if (num % d) == 0
        if (d != (num / d)) && d != 1
          d + (num / d)
        else
          d
        end
      else
        0
      end
    end.inject(0, :+)
  end

  def self.amicable_pair(num)
    partner = divisor_sum(num)

    if num != partner && num == divisor_sum(partner)
      partner
    else
      nil
    end
  end

  def self.solve(max)
    (1..max).map{|n| amicable_pair(n)}.compact.inject(0, :+)
  end
end
