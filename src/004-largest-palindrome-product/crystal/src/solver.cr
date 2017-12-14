module Solver
  def self.solve(digits)
    min = 10**(digits-1)
    max = 10**digits
    (min...max).map do |a|
      (a...max).select do |b|
        is_palindrome?(a * b)
      end.map do |b|
        a * b
      end.push(0).max
    end.max
  end

  def self.is_palindrome?(num)
    cur = num
    rev = 0
    while cur > 0
      rev *= 10
      rev += (cur % 10)
      cur /= 10
    end

    rev == num
  end
end
