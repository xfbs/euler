require "./src/solver"

raise "no datafile specified" if ARGV.size < 1

triangle = File
  .read(ARGV[0])
  .split("\n")
  .select { |l| !l.empty? }
  .map { |l| l.split(" ").map { |e| e.to_i } }

puts Solver.solve(triangle)
