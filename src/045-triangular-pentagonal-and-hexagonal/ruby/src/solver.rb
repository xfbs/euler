module Solver
  def self.solve(t, p, h)
    tt = triangular(t)
    pp = pentagonal(p)
    hh = hexagonal(h)

    while true
      is_pentagonal = false
      is_triangular = false
      h += 1
      hh = hexagonal h

      while tt <= hh
        t += 1
        tt = triangular t
        is_triangular = true if tt == hh
      end

      while pp <= hh
        p += 1
        pp = pentagonal p
        is_pentagonal = true if pp == hh
      end

      return hh if is_triangular && is_pentagonal
    end
  end

  def self.triangular n
    n * (n + 1) / 2
  end

  def self.pentagonal n
    n * (3 * n - 1) / 2
  end

  def self.hexagonal n
    n * (2 * n - 1)
  end
end
