module Solver
  def self.p x
    x * (3 * x - 1) / 2
  end

  def self.p_inverse y
    (1.0 / 6.0) + Math.sqrt((1.0 / 6.0)**2 - (-2.0 / 3.0) * y)
  end

  def self.is_p x
    p(p_inverse(x).round) == x
  end

  def self.b n
    (3 * n * n + 5 * n) / 2
  end

  def self.solve
    i = 1
    loop do
      p_i = p(i)

      n = 1
      while b(n) <= p_i
        if ((p_i - b(n)) % (3 * n)) == 0
          x = (p_i - b(n)) / (3 * n) + 1

          if is_p(p(x) + p(x + n))
            return p_i
          end
        end

        n += 1
      end

      i += 1
    end
  end
end
