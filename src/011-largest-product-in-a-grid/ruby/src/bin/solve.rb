require_relative '../solver'

throw 'no data file supplied' unless ARGV[0]
grid = File.open(ARGV[0]).read.split("\n").map { |l| l.split(' ').map(&:to_i) }
puts Solver.solve(grid)
