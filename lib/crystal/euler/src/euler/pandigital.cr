require "./factorial"

module Euler
  def self.pandigital(n, nth)
    num = 0

    # this is a bitmap of which digits are taken
    taken = 0;

    while n > 0
      num *= 10

      # which of the remaining digits do we pick?
      choice = nth / factorial64(n-1)
      nth %= factorial64(n-1)

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
      n -= 1
    end

    num
  end
end
