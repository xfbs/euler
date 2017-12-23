module Solver
  def self.solve n
    (1..n).map{|num| thousands_number_word(num).scan(/[a-z]/).length}.inject(:+)
  end

  def self.teens_number_word n
    numbers = {
      1 => 'one',
      2 => 'two',
      3 => 'three',
      4 => 'four',
      5 => 'five',
      6 => 'six',
      7 => 'seven',
      8 => 'eight',
      9 => 'nine',
      10 => 'ten',
      11 => 'eleven',
      12 => 'twelve',
      13 => 'thirteen',
      14 => 'fourteen',
      15 => 'fifteen',
      16 => 'sixteen',
      17 => 'seventeen',
      18 => 'eighteen',
      19 => 'nineteen',
      20 => 'twenty',
      30 => 'thirty',
      40 => 'forty',
      50 => 'fifty',
      60 => 'sixty',
      70 => 'seventy',
      80 => 'eighty',
      90 => 'ninety'
    }

    r = numbers.sort_by{|p| p[0]}.reverse.inject([n, []]) do |s, cur|
      if s[0] >= cur[0]
        [s[0]-cur[0], s[1]+[cur[1]]]
      else
        s
      end
    end

    r[1].join('-')
  end

  def self.hundreds_number_word n
    out = []
    hundreds = n/100
    out << "#{teens_number_word hundreds} hundred" if hundreds > 0
    out << teens_number_word(n%100) if (n%100) > 0
    out.join(' and ')
  end

  def self.thousands_number_word n
    out = []
    thousands = n/1000
    out << "#{hundreds_number_word thousands} thousand" if thousands > 0
    out << hundreds_number_word(n%1000) if (n%1000) > 0
    out.join(', ')
  end
end
