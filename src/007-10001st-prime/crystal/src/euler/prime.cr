module Euler
  class Prime
    def initialize
      @primes = [2,3]
    end

    def nth(p)
      while @primes.size <= p
        self.next
      end

      @primes.unsafe_at(p)
    end

    def next
      cur = @primes.last + 2
      while !check_prime?(cur)
        cur += 2
      end
      @primes.push(cur)
      cur
    end

    def check_prime?(n)
      max = Math.sqrt(n).to_i
      pos = 0
      prime = @primes.unsafe_at(pos)
      while prime <= max
        return false if (n % prime) == 0
        pos += 1
        prime = @primes.unsafe_at(pos)
      end

      true
    end
  end
end
