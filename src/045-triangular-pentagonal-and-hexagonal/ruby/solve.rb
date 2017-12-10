#!/usr/bin/env ruby

module Solve
  def self.solve
    t = 285
    tt = 40755
    p = 165
    pp = 40755
    h = 143
    hh = 40755

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

if __FILE__ == $0
  puts Solve.solve()
end
