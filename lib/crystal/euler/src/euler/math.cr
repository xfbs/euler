module Euler
  # A cached array of factorials, from 0! up to 20!
  #
  # Since it is potentially expensive to calculate factorials, they are
  # cached here so that it is a simple lookup to get one. Unfortunately,
  # `UInt64` is only big enough to hold 20!, which means that we don't keep any
  # larger factorials here.
  @@factorials = (1..20).reduce([1u64]) { |m, c| m.push(m[-1]*c) }.as(Array(UInt64))

  # The value of phi, the golden ratio.
  #
  # This is precomputed and stored to efficiently generate fibonacci numbers
  # with `Euler.fibonacci(n)`.
  PHI   = (Math.sqrt(5) + 1) / 2

  # The value of the square root of 5.
  #
  # This is precomputed and stored to efficiently generate fibonacci numbers
  # with `Euler.fibonacci(n)`.
  ROOT5 = Math.sqrt(5)

  # Returns the `n`th factorial as a `UInt64`.
  #
  # Using the cache `@@factorials`, we look up the `n`th factorial and return it
  # as a `UInt64`. The caller must promise to not call this function with `n >
  # 20`. `UInt64` would overflow with 21!, so we don't store those factorials,
  # meaning that calling it would result in a crash.
  #
  # ## Examples
  #
  # ```
  # Euler.factorial(0).should eq 1
  # Euler.factorial(1).should eq 1
  # Euler.factorial(2).should eq 2
  # Euler.factorial(3).should eq 6
  # Euler.factorial(6).should eq 720
  # ```
  def self.factorial(n)
    @@factorials[n]
  end

  # Generates the `n`th fibonacci number.
  #
  # This uses a fast algorithm based on exponentiation of `Euler::PHI` to
  # generate the `n`th fibonacci number.
  #
  # ## Examples
  #
  # ```
  # Euler.fibonacci(1).should eq 1
  # Euler.fibonacci(2).should eq 1
  # Euler.fibonacci(3).should eq 2
  # Euler.fibonacci(4).should eq 3
  # Euler.fibonacci(5).should eq 5
  # Euler.fibonacci(6).should eq 8
  # ```
  def self.fibonacci(n)
    (PHI**n / ROOT5).round
  end

  # Checks if a number is a palindrome.
  #
  # Quickly checks if a number is a palindrome, meaning that it's digits are the
  # same read backwards as they are read forwards. For example, 1023201 is a
  # palindrome (in base 10).
  # Numbers can be checked for being palindromes in other bases, too.
  #
  # ## Examples
  #
  # ```
  # Euler.is_palindrome(12321).should be_true
  # Euler.is_palindrome(1002101).should be_false
  # Euler.is_palindrome(5, 2).should be_true
  # ```
  def self.is_palindrome?(num, base=10)
    cur = num
    rev = 0
    while cur > 0
      rev *= base
      rev += (cur % base)
      cur /= base
    end

    rev == num
  end

  # Generates the `nth` pandigital of length `len`.
  #
  # Works by generating the `nth` permutation of 1..`len`, and returning that as
  # a number.
  #
  # ## Examples
  #
  # ```
  # Euler.pandigital(len: 5, nth: 3).should eq 12453
  # Euler.pandigital(len: 9, nth: 0).should eq 123456789
  # ```
  def self.pandigital(len, nth)
    num = 0

    # this is a bitmap of which digits are taken
    taken = 0

    while len > 0
      num *= 10

      # which of the remaining digits do we pick?
      choice = nth / factorial(len - 1)
      nth %= factorial(len - 1)

      # find the remaining digit
      digit = 0
      while choice != 0
        choice -= 1 unless (taken & (1 << digit)) > 0
        digit += 1
      end

      while (taken & (1 << digit)) > 0
        digit += 1
      end

      # mark this digit as used
      taken |= 1 << digit

      num += digit + 1
      len -= 1
    end

    num
  end
end
