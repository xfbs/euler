module Solver
  # find the sum of all numbers where the sum of the factorial of the digits is
  # equal to the number itself. such a number can't have more than seven digits
  # since 8 * 9! < 99999999 and there are no greater digits than 9. the approach
  # here is to basically try all numbers and see if they fit
  def self.solve
    # generate factorials of digits in advance
    nums = (0..9).map { |n| (1..n).inject(1, :*) }

    total = 0

    # generate all digits = [...] where |digits| = 7, digits is sorted, and
    # 0 <= digits[n] <= 9
    (0..9).each do |a|
      (a..9).each do |b|
        (b..9).each do |c|
          (c..9).each do |d|
            (d..9).each do |e|
              (e..9).each do |f|
                (f..9).each do |g|
                  digits = [a, b, c, d, e, f, g]
                  total += digit_sum(nums, digits)
                end
              end
            end
          end
        end
      end
    end

    total
  end

  def self.digit_sum(nums, digits)
    # calculate the sum of the factorials of all digits greater
    # than 0
    num = digits.reject { |n| n == 0 }.map { |n| nums[n] }.inject(0, :+)

    # count how many zeroes there are. this is needed because we
    # have two different types of zeroes - for example if the
    # number is 0001204, then the leading zeroes need to be
    # ignored but the embedded zero needs to be counted (0! = 1).
    zeroes = digits.count { |n| n == 0 }

    # if there are 6 (or more) zeroes, then disregard this number
    # since it's not a sum.
    if zeroes < 6
      # add the embedded zeroes to the number.
      while (zeroes + num.to_s.length) > 7
        zeroes -= 1
        num += 1
      end

      return num if digits == num.to_s.rjust(7, '0').chars.map(&:to_i).sort
    end

    0
  end
end
