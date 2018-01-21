module Euler
  # an iterator over the divisors of a number (returns the divisors unsorted)
  class Divisors(T)
    include Iterator(T)

    # creates a new iterator instance over the divisors of `num`.
    def initialize(num : T)
      @num = num
      @cur = 1.as(T)
      @sqrt = T.new(Math.sqrt(num))
      @check = false
    end

    # returns the next divisors, the order in which the divisors are returned is
    # undefined.
    def next
      if @cur > @sqrt
        return self.stop
      end

      if !@check
        if (@num % @cur) == 0
          @check = true
          return @cur
        else
          @cur += 1
          return self.next
        end
      else
        @check = false
        recp = (@num / @cur)

        if @cur != recp && @cur != 1
          @cur += 1
          return recp
        else
          @cur += 1
          return self.next
        end
      end
    end
  end

  # returns an iterator over the divisors of num.
  def self.divisors(num)
    Divisors.new(num)
  end
end
