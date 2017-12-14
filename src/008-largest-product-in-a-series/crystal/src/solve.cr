require "./solver"

raise "no data file specified" unless ARGV[0]
puts Solver.solve(ARGV[0], 13)
