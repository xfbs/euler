module Solver
  # generates the product of the first, tenth, hundredth, etc. up to millionth
  # digit of the champernowne constant
  def self.solve
    [0, 9, 99, 999, 9999, 99999, 999999].map do |n|
      champernowne_digit(n)
    end.reduce(1) { |m, c| m * c }
  end

  # generates the digit that is at pos after the decimal point in the
  # champernowne constant (zero being the first digit after the decimal)
  def self.champernowne_digit(pos)
    mag = 1
    exp = 9

    while pos >= (mag*exp)
      pos -= mag*exp
      exp *= 10
      mag += 1
    end

    off = mag - pos % mag - 1
    num = ((exp/9) + pos / mag) / 10**off

    num % 10
  end
end
