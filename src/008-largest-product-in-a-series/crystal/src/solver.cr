module Solver
  def self.solve(string, length)
    numbers = string.chars.map { |n| n.to_i }

    # step one: find the earliest sequence of non-zero numbers with the
    # specified length. offset denotes the start of this sequence. product is
    # the product of the numbers in this sequence.
    offset = 0
    product = 1_u64
    numbers.each_with_index do |num, index|
      if (index - offset) == length
        break
      end

      if num == 0
        offset = index + 1
        product = 1
      else
        product *= num
      end
    end

    # step two: iterate through the rest of the sequence. when we encounter
    # zeroes, we flag this by raising the zeroes counter until we have moved
    # past the zero, and ignoring the product until then. we keep track of the
    # biggest products seen in max.
    zeroes = 0
    max = product
    (string.size - length - offset).times do |i|
      out = numbers[i + offset]
      cur = numbers[i + offset + length]

      if out == 0
        zeroes += 1
      else
        product = product / out
      end

      if cur == 0
        zeroes -= 1
      else
        product = product * cur
      end

      max = product if zeroes == 0 && product > max
    end

    if (numbers.size - offset) < length
      0
    else
      max
    end
  end
end
