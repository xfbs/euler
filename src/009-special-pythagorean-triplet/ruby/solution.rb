module Solution
  def self.solve n
    (((n-3)/3)..(n-1)).each do |c|
      (((n-c-1)/2)..[c, n-c].min).each do |b|
        a = n - c - b
        if is_pythagorean_triplet?(a, b, c)
          return a*b*c
        end
      end
    end
  end

  def self.is_pythagorean_triplet?(a, b, c)
    return false if a > b
    return false if b > c
    return false unless a**2 + b**2 == c**2
    true
  end
end
