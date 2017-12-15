module Solver
  def self.solve(amount)
    amounts = [200, 100, 50, 20, 10, 5, 2, 1]
    change amounts, amount
  end

  def self.change(coins, value)
    return 1 if coins.size == 1
    (0..(value/coins[0])).map do |n|
      change coins[1..-1], (value - n*coins[0])
    end.sum
  end
end
