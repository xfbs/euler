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
    @primes.take_while{|p| p <= max}.each do |d|
      return false if (n % d) == 0
    end
    true
  end
end
