require "euler/divisor_sum"

module Solver
  def self.solve max
    # generate a list of abundant numbers up to max
    abundant = []
    (1..max).each do |n|
      if Euler.divisor_sum(n) > n
        abundant << n
      end
    end

    poss = Array.new(max)
    # generate a list of all possible sums under max
    abundant.each_with_index do |a, i|
      abundant[i..-1].each do |b|
        sum = a + b
        if sum >= max
          break
        end

        poss[sum] = true
      end
    end

    poss.each_with_index.select{|p, _| !p}.map{|_, n| n}.inject(0, :+)
  end
end
