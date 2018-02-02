require "euler/divisors"

module Solver
  def self.solve(max)
    # generate a list of abundant numbers up to max
    abundant = [] of Int32
    (1..max).each do |n|
      if Euler.divisors(n).sum > n
        abundant << n
      end
    end

    # generate a list of all possible sums under max
    poss = Array(Bool).new(max, false)
    abundant.each_with_index do |a, i|
      abundant[i..-1].each do |b|
        sum = a + b
        if sum >= max
          break
        end

        poss[sum] = true
      end
    end

    poss
      .each_with_index
      .select { |a| !a[0] }
      .map { |a| a[1] }
      .sum
  end
end
