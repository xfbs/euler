module Solver
  def self.solve(words)
    # since english words are not usually longer than about 200 characters,
    # generating the first 100 triangle numbers should be sufficient.
    triangle_numbers = (1..100).map{|n| n * (n + 1) / 2}

    # convert words to numbers, filter those that are triangle numbers, and
    # finally count them.
    words
      .map{|w| w.bytes.map{|c| c - "A".bytes[0] + 1}.sum}
      .count{|n| triangle_numbers.includes? n}
  end
end
