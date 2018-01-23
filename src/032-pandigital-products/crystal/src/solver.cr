module Solver
  def self.solve
    # generate an array with all numbers from 1 to 9, generate all the
    # permutations of these numbers, generate all pandigital product sums from
    # those permutations, remove those permutations that do not have pandigital
    # product sums, remove duplicates and compute the sum.
    (1..9)
      .to_a
      .permutations(9)
      .map { |s| pandigital_product_sums(s) }
      .compact
      .flatten
      .uniq
      .sum
  end

  # given an array of digits, compute all pandigital product sums
  def self.pandigital_product_sums(digits)
    sums = nil

    # sums come in these forms:
    # 1 * 2345 = 6789
    # 12 * 345 = 6789
    # 123 * 45 = 6789
    # 1234 * 5 = 6789
    # we basically only have to check the first two cases, since the other two
    # cases are covered when
    # 5 * 1234 = 6789
    # 45 * 123 = 6789
    # (since all permutations are checked). so we iterate over the possible
    # lengths of the first number, compute the length of the second, and check
    # if it's a valid pandigital product sum. if so, we create an array and add
    # the sum to it, if not we'll return nil to avoid creating a new array.
    (1..2).each do |len_a|
      len_b = 5 - len_a

      pos = 0
      a = 0
      b = 0
      p = 0
      len_a.times do
        a *= 10
        a += digits[pos]
        pos += 1
      end
      len_b.times do
        b *= 10
        b += digits[pos]
        pos += 1
      end
      4.times do
        p *= 10
        p += digits[pos]
        pos += 1
      end

      if (a * b) == p
        (sums ||= [] of Int32) << p
      end
    end

    sums
  end
end
