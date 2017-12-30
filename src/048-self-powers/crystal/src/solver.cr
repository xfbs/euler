module Solver
  def self.solve(max, digits)
    mod = 10u64**digits

    (1..max).reduce(0u64) do |m, c|
      (m + pow(c.to_u64, c.to_u64, mod)) % mod
    end
  end

  def self.pow(n : UInt64, e : UInt64, m : UInt64)
    if e == 0
      1u64
    elsif e == 1
      n % m
    elsif (e % 2) == 0
      pow(mult(n, n, m), e / 2, m) % m
    else
      mult(pow(mult(n, n, m), e / 2, m) % m, n, m)
    end
  end

  def self.mult(a : UInt64, b : UInt64, m : UInt64) : UInt64
    pow32 = 2u64**32
    ah = a / pow32
    bh = b / pow32
    al = a % pow32
    bl = b % pow32

    res  = al * bl
    res %= m
    res += shift(ah * bl % m, 32u8, m)
    res %= m
    res += shift(al * bh % m, 32u8, m)
    res %= m
    res += shift(bh * ah % m, 64u8, m)
    res %= m

    res
  end

  def self.shift(n : UInt64, a : UInt8, m : UInt64)
    if a == 0
      n % m
    else
      shift((n << 1) % m, a - 1, m)
    end
  end
end
