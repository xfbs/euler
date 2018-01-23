module Solver
  def self.solve(power)
    # generate all fifth powers of digits
    nums = (0..9).map { |n| n**power }

    # find all numbers where the sum of the fifth powers of the digits is equal
    # to the number itself
    total = 0
    (0..9).each do |a|
      (a..9).each do |b|
        (b..9).each do |c|
          (c..9).each do |d|
            (d..9).each do |e|
              (e..9).each do |f|
                # digits of the number (sorted)
                digits = [a, b, c, d, e, f]

                # sum of the digit of the fifth power
                sum = digits.map { |n| nums[n] }.sum

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
      sum_digits = sum.to_s.rjust(6, '0').chars.map { |c| c.to_i }

      sum_digits.sort == digits
    end
  end
end
