module Solver
  def self.solve(max, digits)
    mod = 10**digits

    (1..max).inject(0) do |m, c|
      m = (m + pow(c, c, mod)) % mod
    end
  end

  def self.pow(n, e, m)
    if e == 0
      1
    elsif e == 1
      n % m
    elsif e.even?
      pow(n**2 % m, e / 2, m) % m
    else
      ((pow(n**2 % m, e / 2, m) % m) * n) % m
    end
  end
end
