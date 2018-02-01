module Euler
  # An iterator over the divisors of a number.
  #
  # This is not the most efficient code as it just brute forces divisors from
  # one until the square root of the number. It returns all proper divisors —
  # meaning divisors that are smaller than the number itself.
  #
  # The order in which this iterator returns the divisors in unspecified — if
  # you need them to be sorted, you have to do that manually.
  #
  # You can use this class directly, or you can use the `Euler.divisors()`
  # function which just wraps it and saves you from having to type
  # `Euler::Divisors.new(num)`.
  class Divisors(T)
    include Iterator(T)

    # Creates a new iterator instance over the divisors of `num`.
    #
    # Since this class is generic, whatever type `num` has is also the type of
    # the divisors that will be returned. Note that this class probably won't
    # work with floating-point variables, so make sure `num` is an integral
    # type.
    #
    # ## Examples
    #
    # ```
    # divisors = Euler::Divisors.new(55)
    # divisors[0] == 1 # ==> true
    # divisors[1] == 5 # ==> true
    # ```
    def initialize(num : T)
      @num = num
      @cur = 1.as(T)
      @sqrt = T.new(Math.sqrt(num))
      @check = false
    end

    # Returns the next divisor, or Iterator::Stop to signal that there aren't
    # any left.
    #
    # ## Examples
    #
    # ```
    # div = Euler::Divisors.new(12)
    # div.next == 1 # ==> true
    # div.next == 2 # ==> true
    # div.next == 3 # ==> true
    # div.next == 4 # ==> true
    # div.next == 6 # ==> true
    # div.next == Iterator::Stop # ==> true
    # ```
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

  # Returns an iterator over the divisors of `num`.
  #
  # Constructs and returns a new instance of `Euler::Divisors(T)`, where `T` is
  # the type of `num`.
  #
  # ## Examples
  #
  # ```
  # divisors(10).sum == 8   # ==> true
  # divisors(11).count == 1 # ==> true
  # ```
  def self.divisors(num)
    Divisors.new(num)
  end
end
