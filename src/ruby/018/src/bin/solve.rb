require_relative '../solver'

throw 'no datafile specified' if ARGV.empty?
triangle = File.open(ARGV[0]).read.split("\n").map { |l| l.split(' ').map(&:to_i) }
puts Solver.solve(triangle)
