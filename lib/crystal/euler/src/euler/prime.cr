module Euler
  class Prime
    include Iterator(Int32)

    # initializes new prime empty prime generator, with 2 and 3 pre-generated.
    def initialize
      @primes = [2, 3]
    end

    # returns the nth prime, either by looking it up in it's cache or by
    # generating all primes up to it. for large `p`, this is a very slow
    # operation.
    def nth(p)
      while @primes.size <= p
        self.next
      end

      @primes.unsafe_at(p)
    end

    # generates the next prime that is larger than all cached primes.
    def next
      cur = @primes.last + 2
      while !check_fast?(cur)
        cur += 2
      end
      @primes.push(cur)
      cur
    end

    # returns an iterator over the prime numbers. when `#nth()` is called while
    # iterating over the iterator, it might mess it up with the current
    # implementation.
    def iter
      @primes.each.chain(self)
    end

    # checks if a number is prime, assuming that we already generated primes up
    # to `sqrt(n)`. use `#check?()` if you are not absolutely sure that is true.
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

    # checks if a number is prime by testing if any prime numbers up to
    # `sqrt(n)` are proper divisors of it.
    def check?(n)
      max = Math.sqrt(n).to_i

      while @primes.last <= max
        self.next
      end

      check_fast? n
    end

    # returns `nil` if n is not prime, or a number `i` such that `#nth(i) == n`.
    def index(n)
      while n > @primes.last
        self.next
      end

      i = @primes.bsearch_index { |p, i| p >= n }
      if i.nil? || @primes[i.to_u] == n
        i
      else
        nil
      end
    end
  end
end
