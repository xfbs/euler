class Prime
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

  def check_prime?(n)
    max = Math.sqrt(n)

    @primes.each do |p|
      return true if p > max
      return false if (n % p) == 0
    end

    true
  end
end
