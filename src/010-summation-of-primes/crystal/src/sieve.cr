require "bit_array"

class Sieve
  include Enumerable(Int32)

  def initialize(max)
    #@sieve = BitArray.new((max+1)/2, true)
    @sieve = Array(Bool).new((max + 1) / 2, true)
    @sieve[0] = false # 1 is not prime

    (1..Math.sqrt(max)).each do |i|
      cur = 2*i + 1
      if @sieve.unsafe_at(i)
        ((cur * cur)..(max+(max%2))).step(2*cur) do |j|
          pos = (j-1)/2
          @sieve[pos] = false
        end
      end
    end
  end

  def each
    yield 2
    @sieve.each_with_index do |prime, number|
      if prime
        yield 2 * number + 1
      end
    end
  end
end
