module Euler
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
    end.sum
  end
end
