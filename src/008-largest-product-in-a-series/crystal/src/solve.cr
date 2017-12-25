require "./solver"

raise "no data file specified" unless ARGV[0]

# read file
datafile = File.read(ARGV[0])

# number is split across multiple lines, so we remove those newlines
datafile = datafile.split("\n").join("")

puts Solver.solve(datafile, 13)
