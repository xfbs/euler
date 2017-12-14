require "./solver"

raise "no data file supplied" unless ARGV[0]?

names = File.read(ARGV[0]).split(',').map{|n| n[1..-2]}

puts Solver.solve(names)
