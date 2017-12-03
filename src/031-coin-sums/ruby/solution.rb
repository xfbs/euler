module Solution
  def self.solve amount
    amounts = [200, 100, 50, 20, 10, 5, 2, 1]
    change coins: amounts, value: amount
  end

  def self.change coins:, value:
    return 1 if coins.length == 1
    (0..(value/coins[0])).map do |n|
      change coins: coins[1..-1], value: (value - n*coins[0])
    end.inject(:+)
  end
end
