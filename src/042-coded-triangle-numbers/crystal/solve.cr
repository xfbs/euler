require "./src/solver"

raise "no datafile specified" unless ARGV[0]?

words = File
  .read(ARGV[0])
  .split(",")
  .map{|w| w[1..-2]}

puts Solver.solve(words)
