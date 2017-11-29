module Solution
  def self.solve filename, len
    # read file
    f = File.open(filename, 'r').read

    # number is split across multiple lines, so we remove those newlines
    f = f.split("\n").join('')

    greatest_substring_product(f, len)
  end

  def self.greatest_substring_product string, length
    numbers = string.chars.map{|n| n.to_i}

    # step one: find the earliest sequence of non-zero numbers with the
    # specified length. offset denotes the start of this sequence. product is
    # the product of the numbers in this sequence.
    offset = 0
    product = 1
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
    (string.length-length-offset).times do |i|
      out = string[i+offset].to_i
      cur = string[i+offset+length].to_i

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

    if (numbers.length - offset) < length
      0
    else
      max
    end
  end
end
