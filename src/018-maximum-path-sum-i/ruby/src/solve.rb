require_relative 'solver'

throw "no datafile specified" if ARGV.length < 1
triangle = File.open(ARGV[0]).read.split("\n").map{|l| l.split(" ").map{|e| e.to_i}}
puts Solver.solve(triangle)
