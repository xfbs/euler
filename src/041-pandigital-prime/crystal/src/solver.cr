require "euler/prime"
require "euler/pandigital"
require "euler/factorial"

module Solver
  def self.solve(num)
    primes = Euler::Prime.new

    num.step(to: 1, by: -1).each do |n|
      Euler.factorial64(n).step(to: 1, by: -1) do |nth|
        permutation = Euler.pandigital(n, nth - 1)
        if primes.check? permutation
          return permutation
        end
      end
    end

    0
  end
end
