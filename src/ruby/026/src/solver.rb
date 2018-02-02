module Solver
  @@pow = Hash.new { |h, i| h[i] = 10**i - 1 }

  def self.solve(max)
    (1..max).map { |n| [n, reciprocal_cycle(n)] }.max_by { |n| n[1] }[0]
  end

  def self.reciprocal_cycle(num)
    num /= 2 while num.even?
    num /= 5 while (num % 5) == 0
    return 0 if num == 1

    cycle = 1
    cycle += 1 while (@@pow[cycle] % num) != 0
    cycle
  end
end
