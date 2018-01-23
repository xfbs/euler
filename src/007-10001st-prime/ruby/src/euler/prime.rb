module Euler
  class Prime
    include Enumerable

    def initialize
      @primes = [2, 3]
    end

    def nth(p)
      self.next while @primes.length <= p

      @primes[p]
    end

    def next
      cur = @primes.last + 2
      cur += 2 until check_prime?(cur)
      @primes.push(cur)
      cur
    end

    def each
      @primes.each do |p|
        yield p
      end

      loop do
        yield self.next
      end
    end

    def check_prime?(n)
      max = Math.sqrt(n).floor

      @primes.each do |p|
        return true if p > max
        return false if (n % p) == 0
      end

      true
    end

    def check?(n)
      max = Math.sqrt(n).to_i

      self.next while @primes.last <= max

      check_prime? n
    end

    def index(n)
      self.next while n > @primes.last

      i = @primes.bsearch_index { |p, _| p >= n }
      i if i.nil? || @primes[i] == n
    end
  end
end
