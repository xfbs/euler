module Solver
  def self.solve(n)
    (1..n).map{|num| thousands_number_word(num)}.sum
  end

  def self.teens_number_word(n)
    numbers = {
      1  => 3, # one
      2  => 3, # two
      3  => 5, # three
      4  => 4, # four
      5  => 4, # five
      6  => 3, # six
      7  => 5, # seven
      8  => 5, # eight
      9  => 4, # nine
      10 => 3, # ten
      11 => 6, # eleven
      12 => 6, # twelve
      13 => 8, # thirteen
      14 => 8, # fourteen
      15 => 7, # fifteen
      16 => 7, # sixteen
      17 => 9, # seventeen
      18 => 8, # eighteen
      19 => 8, # nineteen
      20 => 6, # twenty
      30 => 6, # thirty
      40 => 5, # forty
      50 => 5, # fifty
      60 => 5, # sixty
      70 => 7, # seventy
      80 => 6, # eighty
      90 => 6, # ninety
    }

    numbers.to_a.sort_by{|p| p[0]}.reverse.reduce([n, 0]) do |s, cur|
      if s[0] >= cur[0]
        [s[0]-cur[0], s[1]+cur[1]]
      else
        s
      end
    end[1]
  end

  def self.hundreds_number_word(n)
    out = 0
    hundreds = n/100

    # thirty-three hundred
    out += teens_number_word(hundreds) + 7 if hundreds > 0

    # and
    out += 3 if hundreds > 0 && (n % 100) > 0

    # fourty-five
    out += teens_number_word(n%100) if (n%100) > 0

    out
  end

  def self.thousands_number_word(n)
    out = 0
    thousands = n/1000

    # three hundred and forty-five thousand
    out += hundreds_number_word(thousands) + 8 if thousands > 0

    # five hundred and sixty-seven
    out += hundreds_number_word(n%1000) if (n%1000) > 0

    out
  end
end
