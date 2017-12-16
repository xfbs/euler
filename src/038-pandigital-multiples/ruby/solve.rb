module Solve
  def self.solve
    pandigitals = []
    (1..9999).each do |b|
      pandigital = check_pandigital_multiples(b)
      pandigitals << pandigital if pandigital
    end

    pandigitals.max
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
    num = (1..n).map{|n| (n*base).to_s}.join.to_i

    return check_pandigital(num), num
  end

  def self.check_pandigital num
    chars = num.to_s.chars
    return false if chars.size != 9

    "123456789".chars.each do |c|
      return false unless chars.count{|i| i == c} == 1
    end

    true
  end
end

if __FILE__ == $0
  puts Solve.solve()
end
