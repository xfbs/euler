require 'euler/prime'

module Solver
  def self.solve(max)
    # so, this prime generator has the tiny little problem that when you use
    # prime.nth or prime.index while you use prime.iter, it kinds fucks up
    # everything. so, to save the day, we gotta gen all the primes before
    primes = Euler::Prime.new
    primes.index(max)

    rotates = []

    primes.take_while { |p| p < max }.each do |p|
      c = circular(primes, p)
      next unless c
      c.each do |i|
        rotates << primes.nth(i) unless rotates.include? primes.nth(i)
      end
    end

    rotates.size
  end

  def self.circular(primes, p)
    digits = p.to_s.chars.map(&:to_i)

    circle = (0...digits.size)
             .map do |r|
               cur = 0
               (0...digits.size).each do |i|
                 cur *= 10
                 cur += digits[(i + r) % digits.size]
               end
               cur
             end
             .map do |n|
      primes.index(n)
    end

    circle.map { |n| (n || 0).to_i } if circle.all? { |n| n }
  end
end
