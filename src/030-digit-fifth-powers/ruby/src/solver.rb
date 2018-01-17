module Solver
  def self.solve(power)
    # generate all fifth powers of digits
    nums = (0..9).map{|n| n**power}

    # find all numbers where the sum of the fifth powers of the digits is equal
    # to the number itself
    total = 0
    for a in 0..9 do
      for b in a..9 do
        for c in b..9 do
          for d in c..9 do
            for e in d..9 do
              for f in e..9 do
                # digits of the number (sorted)
                digits = [a, b, c, d, e, f]

                # sum of the digit of the fifth power
                sum = digits.map{|n| nums[n]}.inject(0, &:+)

                # check if sum of fifth powers of digit is equal to sum
                if digit_power_sum? digits, sum
                  total += sum
                end
              end
            end
          end
        end
      end
    end

    total
  end

  def self.digit_power_sum?(digits, sum)
    if sum == 1
      false
    else
      sum_digits = sum.to_s.rjust(6, '0').chars.map(&:to_i)

      sum_digits.sort == digits
    end
  end
end
