require "./src/solver"

raise "no data file supplied" unless ARGV[0]

grid = File
  .read(ARGV[0])
  .split("\n")
  .select { |l| !l.empty? }
  .map { |l| l.split(' ') }
  .map { |l| l.map { |c| n = c.to_i } }

puts Solver.solve(grid)
