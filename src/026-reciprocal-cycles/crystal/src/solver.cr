require "big"

module Solver
  @@pow = Hash(Int32, UInt64 | BigInt).new do |h, i|
    if (i < 64)
      h[i] = 10_u64**i - 1
    else
      h[i] = BigInt.new(10)**i - 1
    end
  end

  def self.solve(max)
    (1..max).map { |n| [n, reciprocal_cycle(n)] }.max_by { |n| n[1] }[0]
  end

  def self.reciprocal_cycle(num)
    while (num % 2) == 0
      num /= 2
    end
    while (num % 5) == 0
      num /= 5
    end
    return 0 if num == 1

    cycle = 1
    while (@@pow[cycle] % num) != 0
      cycle += 1
    end
    cycle
  end
end
