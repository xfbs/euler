module Euler
  class Prime
    include Iterator(Int32)

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
      while !check_fast?(cur)
        cur += 2
      end
      @primes.push(cur)
      cur
    end

    def iter
      @primes.each.chain(self)
    end

    def check_fast?(n)
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

    def check?(n)
      max = Math.sqrt(n).to_i

      while @primes.last <= max
        self.next
      end

      check_fast? n
    end

    def index(n)
      while n > @primes.last
        self.next
      end

      i = @primes.bsearch_index {|p, i| p >= n}
      if i.nil? || @primes[i.to_u] == n
        i
      else
        nil
      end
    end
  end
end
