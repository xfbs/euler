require "../solver"

raise "no data file supplied" unless ARGV[0]
numbers = File.read(ARGV[0]).split("\n").select{|l| !l.empty?}
puts Solver.solve(numbers)
