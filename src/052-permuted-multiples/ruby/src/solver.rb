module Solver
  def self.solve
    # almost a one-liner and cute, but not exactly efficient.
    #(1..100000000)
    #  .find{|n| [2,3,4,5,6].map{|i| (i*n).to_s.chars.sort}.uniq.length == 1}

    (2..10).each do |exp|
      ((10**exp)..(10**(exp+1) / 6)).each do |i|
        return i if is_permuted_multiple?(i)
      end
    end
  end

  def self.is_permuted_multiple? i
    digits = num_to_digits_rev(2*i).sort

    [3,4,5,6].each do |n|
      return false unless digits == num_to_digits_rev(n*i).sort
    end

    true
  end

  def self.num_to_digits_rev n
    digits = []

    while n != 0
      digits << n % 10
      n /= 10
    end

    digits
  end
end
