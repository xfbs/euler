require_relative 'solver'

throw "no data file supplied" unless ARGV[0]
numbers = File.open(ARGV[0]).read.split("\n")
puts Solver.solve(numbers)
