require "euler/prime"

module Solver
  # find the prime smaller than max that is the sum of the most consecutive
  # primes.
  def self.solve(max)
    primes = Euler::Prime.new

    # find the maximum amount of consecutive primes that you can add up to be
    # smaller than max, and their sum.
    max_len = 0
    sum_pre = 0u64
    primes.iter.each do |p|
      break if (p + sum_pre) > max
      max_len += 1
      sum_pre += p
    end

    max_len.downto(2).each do |len|
      sum = sum_pre
      sum_pre -= primes.nth(len-1)

      (len..max_len).each do |i|
        return sum if primes.check? sum

        sum -= primes.nth(i-len)
        sum += primes.nth(i)
      end
    end
  end
end
