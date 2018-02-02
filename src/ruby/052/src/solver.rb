module Solver
  # finds the smallest integer x, such that 2x, 3x, 4x, 5x, and 6x contain the
  # same digits.
  def self.solve
    (2..10).each do |exp|
      ((10**exp)..(10**(exp + 1) / 6)).each do |i|
        return i if is_permuted_multiple?(i)
      end
    end
  end

  # for a given number x, check if 2x, 3x, 4x, 5x and 6x contain the same digits
  def self.is_permuted_multiple?(x)
    digits = num_to_digits_rev(2 * x).sort

    [3, 4, 5, 6].each do |n|
      return false unless digits == num_to_digits_rev(n * x).sort
    end

    true
  end

  # takes a number n and returns an array with the digits (in reverse order)
  def self.num_to_digits_rev(n)
    digits = []

    while n != 0
      digits << n % 10
      n /= 10
    end

    digits
  end
end
