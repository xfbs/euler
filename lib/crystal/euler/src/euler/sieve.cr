module Euler
  # Prime sieve class
  #
  # This prime sieve can be used to efficiently generate large numbers of
  # primes. It takes more space than `Euler::Prime`, but requires less
  # time.
  class Sieve
    include Enumerable(UInt64)

    # Creates a new prime sieve instance.
    #
    # Unlike the `Euler::Prime` generator, which can dynamically generate
    # primes, this generator needs to know in advance up to which number it
    # should check for primes.
    #
    # Constructing a Prime::Sieve with a `max` of 200 means that numbers up to
    # 200 will be checked for primality.
    #
    # ## Examples
    #
    # ```
    # # new prime generator
    # sieve = Euler::Sieve.new(100)
    #
    # sieve.count.should eq 25
    # ```
    def initialize(max)
      @sieve = (1u64..max).step(2).to_a.as(Array(UInt64))
      @sieve[0] = 2u64

      @sieve.each.skip(1).each do |p|
        next unless p
        break if p*p > max

        (p*p).step(to: max, by: 2*p) do |m|
          @sieve[(m - 1)/2] = 0u64
        end
      end
    end

    # Iterate over all the primes.
    #
    # For convenience, this generator uses `Enumerable(UInt64)` to provide a
    # simple interface for iterating over all of the primes.
    #
    # ## Examples
    #
    # ```
    # # new prime generator
    # sieve = Euler::Sieve.new(1000)
    #
    # # sum up primes (sum is an Enumerable(T) method)
    # sieve.sum.should eq 76127
    # ```
    def each
      @sieve.each do |p|
        next unless p > 0
        yield p
      end
    end
  end
end
