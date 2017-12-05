#!/usr/bin/env ruby

module Solve
  def self.solve
    pandigital = []
    (1..9999).each do |b|
      pandigital << check_pandigital_multiples(b)
    end

    pandigital.compact.max
  end

  def self.check_pandigital_multiples base
    (2..9).each do |n|
      works, num = check_pandigital_multiple base, n
      return num if works
      break if num > 987654321
    end
    
    nil
  end

  def self.check_pandigital_multiple base, n
    num = (1..n).map{|m| (m*base).to_s}.join.to_i

    return check_pandigital(num), num
  end

  def self.check_pandigital num
    num.to_s.chars.sort.join == "123456789"
  end
end

if __FILE__ == $0
  puts Solve.solve()
end
