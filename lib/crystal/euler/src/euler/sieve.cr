module Euler
  class Sieve
    include Enumerable(UInt64)

    # creates a new prime sieve capable of holding `max` primes.
    def initialize(max)
      @sieve = (1u64..max).step(2).to_a.as(Array(UInt64))
      @sieve[0] = 2u64

      @sieve.each.skip(1).each do |p|
        next unless p
        break if p*p > max

        (p*p).step(to: max, by: 2*p) do |m|
          @sieve[(m-1)/2] = 0u64
        end
      end
    end

    # iterate over each prime number in the sieve
    def each
      @sieve.each do |p|
        next unless p > 0
        yield p
      end
    end
  end
end
