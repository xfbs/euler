module Euler
  # Prime generator class.
  class Prime
    include Iterator(Int32)

    # Creates a new empty prime generator.
    #
    # ## Examples
    #
    # ```
    # primes = Euler::Prime.new
    # ```
    def initialize
      @primes = [2, 3]
    end

    # Returns the `n`th prime.
    #
    # Internally, it generates all primes up to `n`, and then returns the prime
    # at position `n`. This means that for large `n`, it is a slow operation.
    # However, since all the primes up to `n` are cached, subsequent lookups
    # will be faster.
    #
    # Note that this function starts counting at 0, meaning that the first prime
    # is at `nth(0)`.
    #
    # ## Examples
    #
    # ```
    # # new prime generator
    # primes = Euler::Prime.new
    #
    # # get first few primes
    # primes.nth(0).should eq 2
    # primes.nth(1).should eq 3
    # primes.nth(2).should eq 5
    # primes.nth(99).should eq 541
    # ```
    def nth(n)
      while @primes.size <= n
        self.next
      end

      @primes.unsafe_at(n)
    end

    # Generates the next prime.
    #
    # This method generates (at least one) new prime and returns it.
    #
    # ## Example
    #
    # ```
    # # new prime generator
    # primes = Euler::Prime.new
    #
    # primes.next.should eq 5
    # primes.next.should eq 7
    # ```
    def next
      cur = @primes.last + 2
      while !check_fast?(cur)
        cur += 2
      end
      @primes.push(cur)
      cur
    end

    # Returns an iterator over the prime numbers.
    #
    # Note that this iterator assumes that you do not call `nth()` or other
    # methods that may mutate the state of the primes array while iterating over
    # it.
    #
    # ## Examples
    #
    # ```
    # # new prime generator
    # primes = Euler::Prime.new
    #
    # primes.iter.take(10).sum.should eq 129
    # primes.iter.take_while{ |n| n < 100 }.last.should eq 97
    # ```
    def iter
      @primes.each.chain(self)
    end

    # Checks if a number is prime, assuming that we already have all primes up
    # to `sqrt(n)`
    #
    # Tries to divide the number by all primes up to `sqrt(n)`, returns `true`
    # if it can't find a divisor meaning that the number is prime, and `false`
    # otherwise.
    #
    # ## Examples
    #
    # ```
    # # new prime generator
    # primes = Euler::Prime.new
    #
    # primes.check(77).should be_false
    # primes.check(97).should be_true
    # ```
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

    # Checks if a number is prime.
    #
    # Tries to divide the number by all primes up to `sqrt(n)`, returns `true`
    # if it can't find a divisor meaning that the number is prime, and `false`
    # otherwise.
    #
    # ## Examples
    #
    # ```
    # # new prime generator
    # primes = Euler::Prime.new
    #
    # primes.check(77).should be_false
    # primes.check(97).should be_true
    # ```
    def check?(n)
      max = Math.sqrt(n).to_i

      while @primes.last <= max
        self.next
      end

      check_fast? n
    end

    # Performs a reverse lookup on a prime.
    #
    # Given a prime `p`, find out at which position it is (meaning find an `n`
    # such that `nth(n) == p` is true, or returns `nil`.
    #
    # ## Examples
    #
    # ```
    # # new prime generator
    # primes = Euler::Prime.new
    #
    # prime.index(2).should eq 0
    # prime.index(3).should eq 1
    # prime.index(4).should be_nil
    # prime.index(5).should eq 2
    # prime.index(6).should be_nil
    # ```
    def index(p)
      while p > @primes.last
        self.next
      end

      i = @primes.bsearch_index { |c, i| c >= p }

      if i.nil? || @primes[i.to_u] == p
        i
      else
        nil
      end
    end
  end
end
