require 'euler/prime'

module Solver
  def self.solve(count)
    max = 2200
    primes = Euler::Prime.new

    loop do
      # create array of how many prime factors (up to count) each number has
      prime_factors = Array.new(max, 0)
      primes.take_while { |p| p < max }.each do |prime|
        cur = prime

        while cur < max
          prime_factors[cur] += 1 if prime_factors[cur] <= count

          cur += prime
        end
      end

      # check which `count` consecutive numbers have `count` distinct prime
      # factors
      (0..prime_factors.size - count)
        .select { |num| (0...count).all? { |c| prime_factors[num + c] == count } }
        .select { |num| distinct_prime_factors(primes, count, num) }
        .each { |num| return num }

      max *= 2
    end
  end

  def self.distinct_prime_factors(primes, count, num)
    factors = (0...count).map { |o| num + o }.map do |cur|
      res = []
      state = 1
      i = 0
      while cur != state
        factor = 1
        prime = primes.nth(i)

        factor *= prime while (cur % (factor * prime)) == 0
        state *= factor

        res << factor if factor > 1

        i += 1
      end

      res
    end.to_a

    return false unless factors.all? { |f| f.size == count }

    flat = factors.flatten.sort
    return false unless flat == flat.uniq

    true
  end
end
