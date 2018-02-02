module Solver
  def self.solve(max)
    # what is the highest number d1d2..dn such that d1d2..dn..d2d1 < max?
    high = max.to_s[0..((max.to_s.size + 1)/2 - 1)].to_i

    # generate all pairs of palindromes (in base ten)
    # turn the array of palindrome pairs into an array of palindromes
    # make sure all palindromes are smaller than max
    # find those palindromes in base 10 that are also palindromes in base 2
    # compute the sum
    (1..high)
      .map { |n| gen_palindromes(n) }
      .flatten
      .select { |n| n < max }
      .select { |n| is_palindrome?(n, 2) }
      .sum
  end

  # checks if a number is a palindrome in the given base.
  def self.is_palindrome?(num, base = 10)
    flip = 0
    cur = num
    while cur != 0
      flip *= base
      flip += cur % base
      cur /= base
    end

    flip == num
  end

  # generate palindromes from a number in a given base. basically we take the
  # digits of num, d1d2d3...dn, and generate the palindromes d1d2...dn...d2d1
  # and d1d2...dndn...d2d1 and return both in an array.
  def self.gen_palindromes(num, base = 10)
    flip = 0
    cur = num
    exp = 0
    while cur != 0
      exp += 1
      flip *= base
      flip += cur % base
      cur /= base
    end

    [(num/base)*(base**exp) + flip, num*(base**exp) + flip]
  end
end
