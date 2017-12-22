require "euler/divisor_sum"
require "benchmark"

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
    (0...abundant.size).each do |a|
      (a...abundant.size).each do |b|
        sum = abundant[a] + abundant[b]
        break if sum >= max
        poss[sum] = true
      end
    end

    poss.each_with_index.select{|p, _| !p}.map{|_, n| n}.inject(0, :+)
  end
end
