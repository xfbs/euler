module Solver
  # finds the largest palindrome which can be factored into two numbers that
  # are 10^(digits-1) <= n < 10^digits
  def self.solve(digits)
    min_factor = 10**(digits - 1)
    max_factor = 10**digits

    [false, true].each do |lower|
      (max_factor - 1)
        .downto(min_factor)
        .map { |n| palindrome(n, lower) }
        .select { |p| factorizable(p, min_factor, max_factor) }
        .each { |p| return p }
    end
  end

  # create a palindrome by chaining the number to it's reverse. eg. 123 will
  # become either 123321 (lower = false) or 12321 (lower = true).
  def self.palindrome(num, lower)
    rev = 0
    cur = num
    exp = 1

    while cur != 0
      rev *= 10
      rev += cur % 10
      cur /= 10
      exp *= 10
    end

    num /= 10 if lower

    (num * exp) + rev
  end

  # checks if a number n is factorizable into two numbers a and b, for which
  # min_factor <= a < max_factor and min_factor <= b < sqrt(n)
  def self.factorizable(num, min_factor, max_factor)
    (min_factor..Math.sqrt(num).floor).each do |d|
      if (num % d == 0) && ((num / d) >= min_factor) && ((num / d) < max_factor)
        return true
      end
    end

    false
  end
end
