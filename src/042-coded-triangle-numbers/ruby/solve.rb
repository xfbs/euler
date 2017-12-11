#!/usr/bin/env ruby

module Solve
  def self.solve words
    # since english words are not usually longer than about 200 characters,
    # generating the first 100 triangle numbers should be sufficient.
    triangle_numbers = (1..100).map{|n| n * (n + 1) / 2}

    # convert words to numbers, filter those that are triangle numbers, and
    # finally count them.
    words
      .map{|w| w.bytes.map{|c| c - "A".bytes[0] + 1}.inject(0, :+)}
      .count{|n| triangle_numbers.include? n}
  end
end

if __FILE__ == $0
  words = File.open(ARGV[0]).read.split(",").map{|w| w[1..-2]}
  puts Solve.solve(words)
end
