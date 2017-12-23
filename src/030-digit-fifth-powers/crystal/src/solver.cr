module Solver
  def self.solve
    # generate all fifth powers of digits
    nums = (0..9).map{|n| n**5}

    # find all numbers where the sum of the fifth powers of the digits is equal
    # to the number itself
    total = 0
    nums.each_with_index do |fa, ia|
      nums[ia..-1].each_with_index do |fb, ibt|
        ib = ia+ibt
        nums[ib..-1].each_with_index do |fc, ict|
          ic = ib+ict
          nums[ic..-1].each_with_index do |fd, idt|
            id = ic+idt
            nums[id..-1].each_with_index do |fe, iet|
              ie = id+iet
              nums[ie..-1].each_with_index do |fg, igt|
                ig = ie+igt

                # sum of the digit of the fifth power
                sum = fa+fb+fc+fd+fe+fg

                # digits of the number (sorted)
                digits = [ia, ib, ic, id, ie, ig]

                # check if sum of fifth powers of digit is equal to sum
                if sum > 2 && sum < 999999
                  sum_digits = sum.to_s.rjust(6, '0').chars.map{|n| n.to_i}
                  if sum_digits.sort == digits
                    total += sum
                  end
                end
              end
            end
          end
        end
      end
    end

    total
  end
end
