module Solver
  def self.solve
    fractions = [] of Array(Int32)

    (0..9).each do |a|
      (0..9).each do |b|
        (0..9).each do |c|
          (0..9).each do |d|
            if check_fraction(a, b, c, d)
              fractions << [10 * a + b, 10 * c + d]
            end
          end
        end
      end
    end

    fractions = fractions.reduce([1_u64, 1_u64]) do |a, b|
      im = [a[0]*b[0], a[1]*b[1]]
      gcd = im[0].gcd(im[1])
      [im[0] / gcd, im[1] / gcd]
    end
    fractions[1]
  end

  def self.check_fraction(a, b, c, d)
    frac = (10.0 * a + b) / (10.0 * c + d)
    return false if frac > 1.0
    return false if frac == 0

    return true if b == c && frac == (a.to_f / d.to_f)
    return true if a == d && frac == (b.to_f / c.to_f)
    false
  end
end
