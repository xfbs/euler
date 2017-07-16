module Solution
  def self.solve(upto, digits)
    lim = 10**digits

    1.upto(upto).map do |num|
      (num**num) % lim
    end.inject(0, :+) % lim
  end
end
