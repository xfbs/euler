module Solver
  def self.solve
    fractions = []

    (0..9).each do |a|
      (0..9).each do |b|
        (0..9).each do |c|
          (0..9).each do |d|
            fractions << [10 * a + b, 10 * c + d] if check_fraction(a, b, c, d)
          end
        end
      end
    end

    fractions = fractions.inject([1, 1]) { |a, b| [a[0] * b[0], a[1] * b[1]] }
    fractions[1] / fractions[0].gcd(fractions[1])
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
