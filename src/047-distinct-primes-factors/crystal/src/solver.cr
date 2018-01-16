require "euler/prime"

module Solver
  def self.solve(count)
    max = 200000
    primes = Euler::Prime.new

    loop do
      # create array of how many prime factors (up to count) each number has
      prime_factors = Array(UInt8).new(max, 0u8)
      primes.iter.take_while{|p| p < max}.each do |prime|
        cur = prime

        while cur < max
          if prime_factors[cur] <= count
            prime_factors[cur] += 1
          end

          cur += prime
        end
      end

      # check which `count` consecutive numbers have `count` distinct prime
      # factors
      (0..prime_factors.size-count)
        .select{|num| (0...count).all?{|c| prime_factors[num+c] == count}}
        .select{|num| distinct_prime_factors(primes, count, num)}
        .each{|num| return num}

      max *= 2
    end
  end

  def self.distinct_prime_factors(primes, count, num)
    factors = (0...count).map{|o| num + o}.map do |cur|
      res = [] of UInt64
      state = 1
      i = 0
      while cur != state
        factor = 1u64
        prime = primes.nth(i)

        while (cur % (factor * prime)) == 0
          factor *= prime
        end
        state *= factor

        if factor > 1
          res << factor
        end

        i += 1
      end

      res
    end.to_a

    return false unless factors.all?{|f| f.size == count}

    flat = factors.flatten.sort
    return false unless flat == flat.uniq

    true
  end
end
