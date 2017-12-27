module Euler
  @@factorials = (1..20).reduce([1u64]){|m, c|m.push(m[-1]*c)}.as(Array(UInt64))

  def self.factorial64(n)
    @@factorials[n]
  end
end
