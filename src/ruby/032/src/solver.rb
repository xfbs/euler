module Solver
  def self.solve
    (1..9)
      .to_a
      .permutation(9)
      .map { |s| pandigital_product_sums(s) }
      .compact
      .flatten
      .uniq
      .inject(0, :+)
  end

  def self.pandigital_product_sums(digits)
    sums = nil

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

      (sums ||= []) << p if (a * b) == p
    end

    sums
  end
end
