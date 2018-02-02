module Euler
  class Sieve
    include Enumerable

    def initialize(max)
      @sieve = (1..max).step(2).to_a
      @sieve[0] = 2

      @sieve.lazy.drop(1).each do |p|
        next unless p
        break if p * p > max

        (p * p).step(to: max, by: 2 * p) do |m|
          @sieve[(m - 1) / 2] = nil
        end
      end
    end

    def each
      @sieve.each do |p|
        next unless p
        yield p
      end
    end
  end
end
