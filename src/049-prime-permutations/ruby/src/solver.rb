require "euler/prime"

module Solver
  # find the prime smaller than max that is the sum of the most consecutive
  # primes.
  def self.solve(digits, seen)
    primes = Euler::Prime.new
    min = 10**(digits-1)
    max = 10**digits

    # generate all n-digit primes
    candidates = primes
      .take_while{|p| p < max}
      .select{|p| p != seen && p > min}
      .to_a

    candidates.each_with_index do |p, i|
      candidates.each
        .drop(i+1)
        .take_while{|s| (p + 2 * (s-p)) < max}
        .select{|s| test_sequence(primes, p, s-p)}
        .select{|s| is_permutations(p, s-p)}
        .each{|s| return (0..2).inject(0){|m, c| m * 10**digits + p + c * (s-p)}}
    end
  end

  def self.test_sequence(primes, p, s)
    (0..2).each do |i|
      return false unless primes.index(p + i*s)
    end

    true
  end

  def self.is_permutations(p, s)
    list = [p, p+s, p+s+s]
    list = list.map{|n| n.to_s.chars.map{|c| c.to_i}.sort}
    list[0] == list[1] && list[1] == list[2]
  end
end
