module Euler
  class Prime
    include Enumerable

    def initialize
      @primes = [2,3]
    end

    def nth(p)
      while @primes.length <= p
        self.next
      end

      @primes[p]
    end

    def next
      cur = @primes.last + 2
      while !check_prime?(cur)
        cur += 2
      end
      @primes.push(cur)
      cur
    end

    def each
      @primes.each do |p|
        yield p
      end

      while true
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

      while @primes.last <= max
        self.next
      end

      check_prime? n
    end


    def index(n)
      while n > @primes.last
        self.next
      end

      i = @primes.bsearch_index {|p, _| p >= n}
      if i.nil? || @primes[i] == n
        i
      else
        nil
      end
    end
  end
end
