module Solution
  def self.square_of_sums n
    (n**2) * ((n + 1)**2) / 4
  end

  def self.sum_of_squares n
    n * (n + 1) * (2 * n + 1) / 6
  end

  def self.solve n
    self.square_of_sums(n) - self.sum_of_squares(n)
  end
end
