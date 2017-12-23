require "euler/prime_sieve"

module Solver
  def self.solve(max)
    primes = Euler::PrimeSieve.new(max).to_a
    rotates = [] of Int32

    primes.each do |p|
      c = circular(primes, p)
      if c
        c.each do |i|
          rotates << primes[i] unless rotates.includes? primes[i]
        end
      end
    end

    rotates.size
  end

  def self.circular(primes, p)
    digits = p.to_s.chars.map{|d| d.to_i}

    circle = (0...digits.size)
      .map do |r|
        cur = 0
        (0...digits.size).each do |i|
          cur *= 10
          cur += digits[(i+r) % digits.size]
        end
        cur
    end
      .map do |n|
        i = primes.bsearch_index{|c, i| c >= n}
        if i && primes[i] == n
          i
        else
          nil
        end
    end

    if circle.all?{|n| n}
      circle.map{|n| (n || 0).to_i}
    else
      nil
    end
  end
end
