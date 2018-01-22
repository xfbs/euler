module Euler
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
